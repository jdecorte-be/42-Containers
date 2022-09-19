#ifndef MAP_HPP
#define MAP_HPP

#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"

namespace ft
{


    // template <class Key, class T>
    // struct value_type
    // {
    //     typedef Key key_type;
    //     typedef T mapped_type;
    //     typedef std::pair<const key_type, mapped_type> __value_type;
    //     typedef std::pair<key_type&, mapped_type&> nc_ref_pair_type;
    //     typedef std::pair<key_type&&, mapped_type&&> nc_rref_pair_type;

    //     private :
    //         value_type cc;
    // };

    template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
        // 
        // NODE
        // 
        class bt_node
        {
            public :
                bt_node *left;
                bt_node *right;
                bt_node *parent;

                int key;
                // bool color; // 0 = black / 1 = red
                void *content;

                bt_node()  {}

                bt_node(int key) : key(key) {
                    left = NULL;
                    right = NULL;
                    parent = NULL;
                    // color = 0;
                };
        };

        //
        // Iterator
        // 
        template <bool is_const>
        class map_iterator
        {
            public :
                typedef std::pair<const Key, T> pair_type;
                typedef typename std::conditional<is_const, const pair_type, pair_type>::type value_type;
                typedef typename std::conditional<is_const, const bt_node, bt_node>::type node_type;
                typedef size_t size_type;
                typedef std::ptrdiff_t difference_type;


            private : // Node
                node_type *ptr;

                void goNextNode() {
                    if(ptr->left)
                        ptr = ptr->left;

                }

                void goPrevNode() {

                }


            public : // Function ========

                map_iterator() : ptr(NULL) {}
                map_iterator(node_type *ptr) : ptr(ptr) {}

                node_type *base() {
                    return ptr;
                }

                // operator
                map_iterator &operator=(const map_iterator &src) {
                    ptr = src.base();
                    return *this;
                }

                map_iterator &operator++() {
                    ++ptr;
                    return *this;
                }

                map_iterator operator++(int) {
                    map_iterator tmp(*this);
                    ++(*this);
                    return tmp;
                }

                map_iterator &operator--() {
                    --ptr;
                    return *this;
                }

                map_iterator operator--(int) {
                    map_iterator tmp(*this);
                    --(*this);
                    return tmp;
                }

                map_iterator operator+ (difference_type n) const {
                    map_iterator iter(*this);
                    iter += n;
                    return iter;
                }

                map_iterator operator- (difference_type n) const {
                    return *this + (-n);
                }

                map_iterator& operator+= (const difference_type &n) {
                    ptr += n;
                    return *this;
                }

                map_iterator& operator-= (const difference_type &n) {
                    *this += -n;
                    return *this;
                }

                value_type& operator*() const {
                    return *ptr;
                }

                value_type* operator->() const {
                    return &(operator*());
                }

                template <bool B>
                bool operator==(const map_iterator<B> tocomp) {
                    return ptr == tocomp.base();
                }

                template <bool B>
                bool operator!=(const map_iterator<B> tocomp) {
                    return ptr != tocomp.base();
                }
        };

        //
        // Value typedef
        // 
        public :
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;


            class value_compare
            {
                protected :
                    key_compare comp;
                    value_compare(key_compare c) : comp(c) {}
                public :
                    bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
            };

        private :
            bt_node *root;


        public :
            typedef typename std::allocator_traits<Alloc>::pointer pointer;
            typedef typename std::allocator_traits<Alloc>::const_pointer const_pointer;

            typedef typename std::allocator_traits<Alloc>::size_type size_type;
            typedef typename std::allocator_traits<Alloc>::difference_type difference_type;

            typedef map_iterator<false> iterator;
            typedef map_iterator<true> const_iterator;

            typedef ft::reverse_iterator<iterator>  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>  const_reverse_iterator;

            //
            // Function
            // 
            map() : root(NULL) {
            }

            explicit map( const key_compare& comp, const Alloc& alloc = Alloc()) : root(NULL), key_compare(comp) {
            }

            template< class InputIt >
            map( InputIt first, InputIt last, const key_compare& comp = key_compare(), const Alloc& alloc = Alloc()) {

            }

            map( const map& other ) {
                
            }


            // typedef typename ft::iterator_traits<iterator>::difference_type difference_type;



            // map(const key_compare &comp = key_compare(), const allocator_type &allocator = allocator_type()) {

            // }
            


            // pair<iterator,bool> insert (const value_type& val) {

            // }

            // iterator insert (iterator position, const value_type& val) {}

            // template <class InputIterator>
            // void insert (InputIterator first, InputIterator last) {}

    };
}

#endif