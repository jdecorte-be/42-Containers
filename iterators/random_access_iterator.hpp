#pragma once

#include <memory>
#include <exception>
#include <stdexcept>
#include <string>
#include <limits>

#include "iterator_traits.hpp"

namespace ft
{
    template <typename Iterator>
        class random_access_iterator
        {
            public :
                typedef Iterator iterator_type;
                typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
                typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
                typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
                typedef typename ft::iterator_traits<iterator_type>::reference reference;
                typedef	typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
            private :
                pointer ptr;
            public :
                // * Default constructor
                random_access_iterator() : ptr(nullptr) {}
                random_access_iterator(pointer newptr) : ptr(newptr) {}
            
                random_access_iterator(const random_access_iterator& src) : ptr(src.ptr) {}; // cpy

                random_access_iterator &operator=(const random_access_iterator& rhs) {
                    if(this == &rhs)
                        return *this;
                    ptr = rhs.ptr;
                    return *this;
                }

                pointer base() const {
                    return ptr;
                }

                // * Destructor
                ~random_access_iterator() {}

                // * reference to the element pointed
                reference operator*() const {
                    return *ptr;
                }
                // * pointer to the element pointed
                pointer operator->() const {
                    return &(operator*());
                }

                // decrements the base iterator
                random_access_iterator& operator++() {
                    ptr++;
                    return *this;
                }
                random_access_iterator  operator++(int) {
                    random_access_iterator tmp = *this;
                    tmp.ptr++;
                    return tmp;
                }

                // increments the base iterator
                random_access_iterator& operator--() {
                    ptr--;
                    return *this;
                }
                random_access_iterator  operator--(int) {
                    random_access_iterator tmp = *this;
                    tmp.ptr--;
                    return tmp;
                }

                // Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to
                random_access_iterator operator+ (difference_type n) const {
                    return ptr + n;
                }
                // applies the binary operator+ on the base iterator and returns a reverse iterator
                random_access_iterator operator- (difference_type n) const {
                    return ptr - n;
                }

                // function decreases by n
                random_access_iterator& operator+= (const difference_type &n) {
                    ptr += n;
                    return *this;
                }
                // increases by n the base iterator 
                random_access_iterator& operator-= (const difference_type &n) {
                    ptr -= n;
                    return *this;
                }

                // * Accesses the element located n positions
                reference operator[] (difference_type n) const {
                    return ptr[n];
                }
        };

        // * equality/inequality operators
        template <typename It>
        typename random_access_iterator<It>::difference_type operator== (const random_access_iterator<It>& lhs, const random_access_iterator<It>& rhs) {
            return lhs.base() == rhs.base();
        }
        // * For const Ite
        template <typename It1, typename It2>
        typename random_access_iterator<It1>::difference_type operator== (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() == rhs.base();
        }

        template <typename It>
        typename random_access_iterator<It>::difference_type operator!= (const random_access_iterator<It>& lhs, const random_access_iterator<It>& rhs) {
            return !(lhs.base() == rhs.base());
        }
        // * For const Ite
        template <typename It1, typename It2>
        typename random_access_iterator<It1>::difference_type operator!= (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return !(lhs.base() == rhs.base());
        }

        // * Relational operators
        template <typename It>
        typename random_access_iterator<It>::difference_type operator<  (const random_access_iterator<It>& lhs, const random_access_iterator<It>& rhs) {
            return lhs.base() < rhs.base();
        }
        // * For const Ite
        template <typename It1, typename It2>
        typename random_access_iterator<It1>::difference_type operator<  (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() < rhs.base();
        }
    
        template <typename It>
        typename random_access_iterator<It>::difference_type operator<= (const random_access_iterator<It>& lhs, const random_access_iterator<It>& rhs) {
            return lhs.base() <= rhs.base();
        }
        // * For const Ite
        template <typename It1, typename It2>
        typename random_access_iterator<It1>::difference_type operator<= (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() <= rhs.base();
        }

        template <typename It>
        typename random_access_iterator<It>::difference_type operator>  (const random_access_iterator<It>& lhs, const random_access_iterator<It>& rhs) {
            return lhs.base() > rhs.base();
        }
        // * For const Ite
        template <typename It1, typename It2>
        typename random_access_iterator<It1>::difference_type operator>  (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() > rhs.base();
        }

        template <typename It>
        typename random_access_iterator<It>::difference_type operator>= (const random_access_iterator<It>& lhs, const random_access_iterator<It>& rhs) {
            return lhs.base() >= rhs.base();
        }
        // * For const Ite
        template <typename It1, typename It2>
        typename random_access_iterator<It1>::difference_type operator>= (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() >= rhs.base();
        }

        template <typename It1, typename It2>
        typename random_access_iterator<It1>::difference_type operator- (It1 &first, It2 &last) {
            return last.base() - first.base();
        }
}
