#include "rb_tree.hpp"

#define COUNT 10

void print2DUtil(rb_node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout << ((root->color == 1) ? "\033[31m" : "\033[34m") << root->key <<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(rb_tree *tree)
{
    // Pass initial space count as 0
    print2DUtil(tree->root, 0);
}

int main()
{
    rb_tree *tree  = new rb_tree;
    tree->insert(4);
    tree->insert(1);
    tree->insert(2);
    tree->insert(5);
    tree->insert(7);
    tree->insert(8);
    tree->insert(9);
    tree->insert(10);
    tree->insert(3);

    print2D(tree);

}