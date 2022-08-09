#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <exception>
#include <stdexcept>
#include <string>
#include <limits>

#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
        class random_access_iterator
        {
            public :
                typedef Iterator iterator_type;
                typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
                typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
                typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
                typedef typename ft::iterator_traits<iterator_type>::reference reference;
                typedef	typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
            private :
                iterator_type ptr;

            public :
                // * Default constructor
                random_access_iterator() : ptr(nullptr) {}
                random_access_iterator(iterator_type newptr) : ptr(newptr) {}

                explicit random_access_iterator(const random_access_iterator& src) : ptr(src.base()) {};
                template <class T>
                random_access_iterator(const random_access_iterator<T>& src) : ptr(src.base()) {};

                random_access_iterator operator=(const random_access_iterator& x) {
                    ptr = x.base();
                    return *this;
                }

                // * base (getter for ptr)
                pointer const &base() const {
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

                // * decrements the base iterator
                random_access_iterator& operator++() {
                    ++ptr;
                    return *this;
                }
                random_access_iterator  operator++(int) {
                    random_access_iterator tmp = *this;
                    ++(*this);
                    return tmp;
                }

                // * increments the base iterator
                random_access_iterator& operator--() {
                    --ptr;
                    return *this;
                }
                random_access_iterator  operator--(int) {
                    random_access_iterator tmp = *this;
                    --(*this);
                    return tmp;
                }

                // * Returns a random iterator pointing to the element located n positions away from the element the iterator currently points to
                random_access_iterator operator+ (difference_type n) const {
                    random_access_iterator iter(*this);
                    iter += n;
                    return iter;
                }
                // * applies the binary operator+ on the base iterator and returns a random iterator
                random_access_iterator operator- (difference_type n) const {
                    random_access_iterator iter(*this);
                    iter -= n;
                    return iter;
                }

                // * function decreases by n
                random_access_iterator& operator+= (const difference_type &n) {
                    ptr += n;
                    return *this;
                }
                // * increases by n the base iterator 
                random_access_iterator& operator-= (const difference_type &n) {
                    ptr -= n;
                    return *this;
                }

                // * Accesses the element located n positions
                reference operator[] (difference_type n) const {
                    return ptr[n];
                }
        };


        template <typename It>
        random_access_iterator<It> operator+ ( typename random_access_iterator<It>::difference_type n, random_access_iterator<It>& src) {
            src += n;
            return src;
        }

        // * equality/inequality operators
        template <typename It1, typename It2>
        bool operator== (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() == rhs.base();
        }

        template <typename It1, typename It2>
        bool operator!= (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return !(lhs.base() == rhs.base());
        }

        template <typename It1, typename It2>
        bool operator<  (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() < rhs.base();
        }
    
        template <typename It1, typename It2>
        bool operator<= (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() <= rhs.base();
        }

        template <typename It1, typename It2>
        bool operator>  (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() > rhs.base();
        }

        template <typename It1, typename It2>
        bool operator>= (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() >= rhs.base();
        }

        template <typename It>
        typename random_access_iterator<It>::difference_type operator- (const random_access_iterator<It>& lhs, const random_access_iterator<It>& rhs) {
            return lhs.base() - rhs.base();
        }


}

#endif // !1 RANDOM_ACCESS_ITERATOR_HPP
