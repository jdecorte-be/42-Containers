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
                reverse_iterator() : iter(nullptr) {}
                explicit reverse_iterator (Iterator it) : iter(it) {}

                template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it) : iter(rev_it.base()) {}

                reverse_iterator operator=(const reverse_iterator& x) {
                    iter = x.base();
                    return *this;
                }
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

        };
        
        // * base
        template <class Iterator>
        typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const {
            return iter;
        }

        // * Pointer-to-member operators
        template <class Iterator>
        typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const {
            iterator_type tmp = iter;
            return *(--tmp);
        }

        // * Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to
        template <class Iterator>
        reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+ (reverse_iterator<Iterator>::difference_type n) const {
            return reverse_iterator(iter - n);
        }

        // * decrements the base iterator
        template <class Iterator>
        reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++() {
            --iter;
            return *this;
        }
        template <class Iterator>
        reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator++(int) {
            reverse_iterator tmp = *this;
            --iter;
            return tmp;
        }

        // * function decreases by n
        template <class Iterator>
        reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+= (difference_type n) {
            iter -= n;
            return *this; 
        }

        // * applies the binary operator+ on the base iterator and returns a reverse iterator
        template <class Iterator>
        reverse_iterator<Iterator> reverse_iterator<Iterator>::operator- (difference_type n) const {
            return reverse_iterator(iter + n);
        }

        // * increments the base iterator
        template <class Iterator>
        reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--() {
            ++iter;
            return *this;
        }
        template <class Iterator>
        reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator--(int) {
            reverse_iterator tmp = *this;
            ++iter;
            return tmp;
        }

        // * increases by n the base iterator 
        template <class Iterator>
        reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-= (difference_type n) {
            iter += n;
            return *this;
        }

        // * pointer to the element pointed
        template <class Iterator>
        typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const {
            return &(operator*());
        }

        // * Accesses the element located n positions
        template <class Iterator>
        typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[] (reverse_iterator<Iterator>::difference_type n) const {
            return *(*this + n);
        }

        // * For const Ite
        template <typename It1, typename It2>
        typename reverse_iterator<It1>::difference_type operator== (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) {
            return lhs.base() == rhs.base();
        }

        // * For const Ite
        template <typename It1, typename It2>
        bool operator!= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) {
            return !(lhs.base() == rhs.base());
        }

        template <typename It1, typename It2>
        bool operator<  (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() > rhs.base(); }
  
        template <typename It1, typename It2>
        bool operator<= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() >= rhs.base(); }

        template <typename It1, typename It2>
        bool operator>  (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() < rhs.base(); }

        template <typename It1, typename It2>
        bool operator>= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() <= rhs.base(); }

        template <typename It>
        typename reverse_iterator<It>::difference_type operator- (const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs) { return rhs.base() - lhs.base(); }

        // * Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it
        template <typename It1, typename It2>
        reverse_iterator<It1> operator+ ( typename reverse_iterator<It1>::difference_type n, const reverse_iterator<It2>& rev_it) {
            return (rev_it.base() - n);
        }

}

#endif
