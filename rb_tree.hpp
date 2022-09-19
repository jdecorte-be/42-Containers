#include <cstdio>
#include <iostream>

class rb_node
{
    public :
        rb_node *left;
        rb_node *right;
        rb_node *parent;

        int key;
        bool color; // 0 = black / 1 = red
        void *content;

        rb_node()  {}

        rb_node(int key) : key(key) {
            left = NULL;
            right = NULL;
            parent = NULL;
            color = 0;
        };
};

class rb_tree
{
    public :
        rb_node *root;

        rb_tree() : root(NULL) {}

        rb_node *newNode(int key) {
            rb_node *tmp = new rb_node;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->parent = NULL;
            tmp->color = 1;
            tmp->key = key;
            return tmp;
        }

        void insert(int k) {
            if(root == NULL)
            {
                root = newNode(k);
                root->color = 0;
                return ;
            }

            rb_node *newnode = newNode(k);

            rb_node *r = root;
            while(r != NULL)
            {
                if(r->key > k)
                {
                    if(r->left == NULL)
                    {
                        r->left = newnode;
                        break ;
                    }
                    else
                        r = r->left;
                }
                else
                {
                    if(r->right == NULL)
                    {
                        r->right = newnode;
                        break ;
                    }
                    else
                        r = r->right;
                }
            }
            newnode->parent = r;
        }
        

};


