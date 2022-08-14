#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP


namespace ft
{
    template <class T>
    class BT_NODE
    {
        public : 
            typedef T value_type;
        
            value_type value;
            bool color; // 0 == black // 1 == red
            BT_NODE *parent;
            BT_NODE *left;
            BT_NODE *right;

            BT_NODE() : value(), color(0), parent(u_nullptr), left(u_nullptr), right(u_nullptr) {}

            BT_NODE(BST_NODE *parent = u_nullptr, BT_NODE *left = u_nullptr, BT_NODE *right = u_nullptr)
            : value(), color(0), parent(parent), left(left), right(right) {}

            BT_NODE(const value_type &val, BST_NODE *parent = u_nullptr, BT_NODE *left = u_nullptr, BT_NODE *right = u_nullptr)
            : value(val), color(0), parent(parent), left(left), right(right) {}

            BT_NODE(const BT_NODE &node) : value(node.val), color(node.color), parent(node.parent), left(node.left), right(node.right) {}
            
            BT_NODE &operator=(const BT_NODE &node)
            {
                if(*this != node)
                {
                    value = node.value;
                    color = node.color;
                    parent = node.parent;
                    left = node.left;
                    right = node.right;
                }
            }
    };


    template <class T, class Compare = std::less<T>, class Node = ft::BT_Node<T>,
            class Type_Alloc = std::allocator<T>, class Alloc = std::allocator<Node> >
    class binary_tree
    {
        public :
            typedef T value_type;
            typedef Node node_type;
            typedef Node* node_pointer;
            typedef Alloc node_alloc;

            typedef size_t size_type;

            binary_tree(const node_alloc &alloc = node_alloc())
                : node_alloc(alloc)
            {
                
            }
    };

}


#endif