#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>

class IndexPointsAluno : public IndexPointsAbstract {
    
public:
    
    long size() ;
        
    void add (float key, long idx ) ;
    
    //look for a range of values
    void find(std::vector<long> &res, float first, float last ) ;
    
    
private: 
    // ALUNO DEVE IMPLEMENTAR ALGO COM O MESMO COMPORTAMENTO DE MULTIMAP
    
    struct node {
        float key;
        long idx;
        struct node* left = nullptr;
        struct node* right = nullptr;
        struct node* parent = nullptr;
        std::string color;
    };

    class RBtree{

        struct node* nil;
        struct node* root;
        long counter;

        public:

            RBtree(){
                nil = nullptr;
                root = nil;
                counter = 0;
            };

            void left_rotate(struct node* oldroot){
                struct node* newroot = oldroot->right;
                oldroot->right = newroot;
                if(newroot->left != nil) 
                    newroot->left->parent = oldroot;
                newroot->parent = oldroot->parent;
                if(oldroot->parent == nil) root = newroot;
                else if(oldroot == oldroot->parent->left)
                    oldroot->parent->left = newroot;
                else oldroot->parent->right = newroot;
                newroot->left = oldroot;
                oldroot->parent = newroot;                
            }

            void right_rotate(struct node* oldroot){
                struct node* newroot = oldroot->left;
                oldroot->left = newroot;
                if(newroot->right != nil) 
                    newroot->right->parent = oldroot;
                newroot->parent = oldroot->parent;
                if(oldroot->parent == nil) root = newroot;
                else if(oldroot == oldroot->parent->right)
                    oldroot->parent->right = newroot;
                else oldroot->parent->left = newroot;
                newroot->right = oldroot;
                oldroot->parent = newroot;                
            }       

            void insert_node(float key, long idx){
                counter++;
                struct node* aux = root;
                struct node* aux2 = nil;
                struct node* newnode;
                newnode->key = key;
                newnode->idx = idx;
                while(aux != nil){
                    aux2 = aux;
                    if(newnode->key < aux->key)
                        aux = aux->left;
                    else aux = aux->right;
                }
                newnode->parent = aux2;
                if(aux2 == nil) root = newnode;
                else if (newnode->key < aux->key) 
                    aux2->left = newnode;
                else aux2->right = newnode;
                newnode->left = nil;
                newnode->right = nil;
                newnode->color = "RED";
                insert_fixup(newnode);
            }

            void insert_fixup(struct node* newnode){
                while(newnode->parent->color == "RED"){
                    if(newnode->parent == newnode->parent->parent->left){
                        struct node* aux = newnode->parent->parent->right;
                        if(aux->color == "RED"){
                            newnode->parent->color = "BLACK";
                            aux->color = "BLACK";
                            newnode->parent->parent->color = "RED";
                            newnode = newnode->parent->parent;
                        }
                        else if(newnode == newnode->parent->right){
                            newnode = newnode->parent;
                            left_rotate(newnode);
                            newnode->parent->color = "BLACK";
                            newnode->parent->parent->color = "RED";
                            right_rotate(newnode->parent->parent);
                        }
                        else{
                            newnode = newnode->parent;
                            right_rotate(newnode);
                            newnode->parent->color = "BLACK";
                            newnode->parent->parent->color = "RED";
                            left_rotate(newnode->parent->parent);                            
                        }
                    }
                }
                root->color = "BLACK";
            }

    };

    RBtree redblack;

};//class


#endif
