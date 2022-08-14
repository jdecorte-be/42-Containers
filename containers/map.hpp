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

    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {
        public :
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;

            class value_compare
                : binary_function<value_type,value_type,bool>
            {
                protected :
                    key_compare comp;
                    value_compare(key_compare c) : comp(c) {}
                public :
                    bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
            };

            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename alloc_traits::pointer pointer;
            typedef typename alloc_traits::const_pointer const_pointer;

            // typedef typename std::bidirectional_iterator_tag<value_type, key_compare>::iterator iterator;
            // typedef typename std::bidirectional_iterator_tag<value_type, key_compare>::const_iterator const_iterator;

            typedef ft::reverse_iterator<iterator>  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>  const_reverse_iterator;

            // typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef typename size_t size_type;



            map(const key_compare &comp = key_compare(), const allocator_type &allocator = allocator_type())








            pair<iterator,bool> insert (const value_type& val) {

            }

            iterator insert (iterator position, const value_type& val) {}

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last) {}

    };
}

#endif