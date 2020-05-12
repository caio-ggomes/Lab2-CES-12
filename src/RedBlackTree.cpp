#include<bits/stdc++.h>
#include "RedBlackTree.h"

long RBtree::get_counter(){
    return this->counter;
}

struct node* RBtree::get_root(){
    return this->root;
}

void RBtree::left_rotate(struct node* oldroot){
    struct node* newroot = oldroot->right;
    oldroot->right = newroot->left;
    if(newroot->left != nil) 
        newroot->left->parent = oldroot;
    newroot->parent = oldroot->parent;
    if(oldroot->parent == nullptr) this->root = newroot;
    else if(oldroot == oldroot->parent->left)
        oldroot->parent->left = newroot;
    else oldroot->parent->right = newroot;
    newroot->left = oldroot;
    oldroot->parent = newroot;                
}

void RBtree::right_rotate(struct node* oldroot){
    struct node* newroot = oldroot->left;
    oldroot->left = newroot->right;
    if(newroot->right != nil) 
        newroot->right->parent = oldroot;
    newroot->parent = oldroot->parent;
    if(oldroot->parent == nullptr) this->root = newroot;
    else if(oldroot == oldroot->parent->right)
        oldroot->parent->right = newroot;
    else oldroot->parent->left = newroot;
    newroot->right = oldroot;
    oldroot->parent = newroot;                
}       

void RBtree::insert_node(float key, long idx){
    this->counter++;

    struct node* aux = this->root;
    struct node* aux2 = nullptr;

    struct node* newnode = new struct node;
    newnode->key = key;
    newnode->idx = idx;
    newnode->parent = nullptr;
    newnode->left = nil;
    newnode->right = nil;
    newnode->color = "RED";

    while(aux != nil){
        aux2 = aux;
        if(newnode->key < aux->key)
            aux = aux->left;
        else aux = aux->right;
    }
    newnode->parent = aux2;
    if(aux2 == nullptr) this->root = newnode;
    else if (newnode->key < aux2->key) 
        aux2->left = newnode;
    else aux2->right = newnode;

    if(newnode->parent == nullptr){
        newnode->color = "BLACK";
        return;
    }

    if(newnode->parent->parent == nullptr){
        return;
    }

    insert_fixup(newnode);
}

void RBtree::insert_fixup(struct node* newnode){
    while(newnode->parent->color == "RED"){
        if(newnode->parent == newnode->parent->parent->right){
            struct node* aux = newnode->parent->parent->left;
            if(aux->color == "RED"){
                newnode->parent->color = "BLACK";
                aux->color = "BLACK";
                newnode->parent->parent->color = "RED";
                newnode = newnode->parent->parent;
            }
            else{
                if(newnode == newnode->parent->left){
                    newnode = newnode->parent;
                    right_rotate(newnode);
                }
                newnode->parent->color = "BLACK";
                newnode->parent->parent->color = "RED";
                left_rotate(newnode->parent->parent);
            }
        }
        else{
            struct node* aux = newnode->parent->parent->right;
            if(aux->color == "RED"){
                newnode->parent->color = "BLACK";
                aux->color = "BLACK";
                newnode->parent->parent->color = "RED";
                newnode = newnode->parent->parent;
            }
            else{ 
                if(newnode == newnode->parent->right){
                    newnode = newnode->parent;
                    left_rotate(newnode);
                }
                newnode->parent->color = "BLACK";
                newnode->parent->parent->color = "RED";
                right_rotate(newnode->parent->parent);
            }                           
        }
        if(newnode == root) break;
    }
    root->color = "BLACK";
}

void RBtree::find(struct node* startnode, std::vector<long> &res, float first, float last){
    if(startnode != nil){
        if(startnode->key >= first && startnode->key <= last){
            res.push_back(startnode->idx);
            find(startnode->left, res, first, last);
            find(startnode->right, res, first, last);
        }
        else if(startnode->key < first) find(startnode->right, res, first, last);
        else find(startnode->left, res, first, last);
    }
}