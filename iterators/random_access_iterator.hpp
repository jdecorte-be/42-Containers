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
            : public ft::iterator<ft::random_access_iterator_tag, Iterator>
        {
            public :
                typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::value_type value_type;
                typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::difference_type difference_type;
                typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::pointer pointer;
                typedef typename ft::iterator<ft::random_access_iterator_tag, Iterator>::reference reference;
                typedef	typename ft::iterator<ft::random_access_iterator_tag, Iterator>::iterator_category iterator_category;
            private :
                pointer ptr;

            public :
                // * Default constructor
                random_access_iterator(pointer newptr) : ptr(newptr) {}
                random_access_iterator(const random_access_iterator<Iterator>& src) : ptr(src.ptr) {};
                operator random_access_iterator<const Iterator>() const {
                    return ptr;
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

                // * Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to
                random_access_iterator operator+ (difference_type n) const {
                    return random_access_iterator(ptr + n);
                }
                // * applies the binary operator+ on the base iterator and returns a reverse iterator
                random_access_iterator operator- (difference_type n) const {
                    return random_access_iterator(ptr - n);
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

        template <typename It>
        typename random_access_iterator<It>::difference_type operator- (const random_access_iterator<It>& lhs, const random_access_iterator<It>& rhs) {
            return lhs.base() - rhs.base();
        }
        // * For const Ite
        template <typename It1, typename It2>
        typename random_access_iterator<It1>::difference_type operator- (const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
            return lhs.base() - rhs.base();
        }
}

#endif // !1 RANDOM_ACCESS_ITERATOR_HPP
