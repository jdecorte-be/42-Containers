#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <memory>
#include <exception>
#include <stdexcept>
#include <string>
#include <limits>

#include "../iterators/iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
        class reverse_iterator
        {
            public :
                typedef Iterator iterator_type;
                typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
                typedef typename iterator_traits<Iterator>::value_type value_type;
                typedef typename iterator_traits<Iterator>::difference_type difference_type;
                typedef typename iterator_traits<Iterator>::pointer pointer;
                typedef typename iterator_traits<Iterator>::reference reference;
            private :
                Iterator iter;
            public :
                // Default constructor
                reverse_iterator() : iter() {}
                explicit reverse_iterator (iterator_type it) : iter(it) {}

                template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it) : iter(rev_it.base()) {}

                // base
                iterator_type base() const;

                // reference to the element pointed
                reference operator*() const;

                // Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to
                reverse_iterator operator+ (difference_type n) const;

                // decrements the base iterator
                reverse_iterator& operator++();
                reverse_iterator  operator++(int);

                // function decreases by n
                reverse_iterator& operator+= (difference_type n);

                // applies the binary operator+ on the base iterator and returns a reverse iterator
                reverse_iterator operator- (difference_type n) const;

                // increments the base iterator
                reverse_iterator& operator--();
                reverse_iterator  operator--(int);

                // increases by n the base iterator 
                reverse_iterator& operator-= (difference_type n);

                // pointer to the element pointed
                pointer operator->() const;

                // Accesses the element located n positions
                reference operator[] (difference_type n) const;

                // Relational operators
                friend bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
                friend bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
                friend bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
                friend bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
                friend bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
                friend bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

                // Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it
                friend reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

                // Returns the distance between lhs and rhs
                friend reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
        };
        
        // base
        template <class Iterator>
        typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const {
            return iter;
        }

        // Pointer-to-member operators
        template <class Iterator>
        typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const {
            iterator_type tmp = iter;
            tmp--;
            return *tmp;
        }

        // Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to
        template <class Iterator>
        reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+ (reverse_iterator<Iterator>::difference_type n) const {
            return reverse_iterator(Iterator(iter - n));
        }

        // decrements the base iterator
        template <class Iterator>
        reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++() {
            --iter;
            return *this;
        }
        template <class Iterator>
        reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator++(int) {
            reverse_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        // function decreases by n
        template <class Iterator>
        reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+= (difference_type n) {
            iter -= n;
            return *this; 
        }

        // applies the binary operator+ on the base iterator and returns a reverse iterator
        template <class Iterator>
        reverse_iterator<Iterator> reverse_iterator<Iterator>::operator- (difference_type n) const {
            return reverse_iterator(Iterator(iter + n));
        }

        // increments the base iterator
        template <class Iterator>
        reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--() {
            ++iter;
            return *this;
        }
        template <class Iterator>
        reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator--(int) {
            reverse_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        // increases by n the base iterator 
        template <class Iterator>
        reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-= (difference_type n) {
            iter += n;
            return *this;
        }

        // pointer to the element pointed
        template <class Iterator>
        typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const {
            return &(operator*());
        }

        // Accesses the element located n positions
        template <class Iterator>
        typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[] (reverse_iterator<Iterator>::difference_type n) const {
            retunr (*this).base()[-n - 1];
        }

        // Relational operators
        template <class Iterator>
        bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return lhs.iter == rhs.iter;
        }
        template <class Iterator>
        bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return lhs.iter != rhs.iter;
        }
        template <class Iterator>
        bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return lhs.iter < rhs.iter;
        }
        template <class Iterator>
        bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return lhs.iter <= rhs.iter;
        }
        template <class Iterator>
        bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return lhs.iter > rhs.iter;
        }
        template <class Iterator>
        bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return lhs.iter >= rhs.iter;
        }

        // ! Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it
        template <class Iterator>
        reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
            return rev_it + n;
        }

        // Returns the distance between lhs and rhs
        template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return rhs.iter - lhs.iter;
        }
}

#endif
