#include<bits/stdc++.h>

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
            nil = new struct node;
            nil->color = "BLACK";
            nil->left = nullptr;
            nil->right = nullptr;
            root = nil;
            counter = 0;
        };

        long get_counter();

        struct node* get_root();

        void left_rotate(struct node* oldroot);

        void right_rotate(struct node* oldroot);       

        void insert_node(float key, long idx);

        void insert_fixup(struct node* newnode);

        void find(struct node* startnode, std::vector<long> &res, float first, float last);

};