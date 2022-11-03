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
			protected :
				Iterator iter;

			public :
				typedef Iterator iterator_type;
				typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
				typedef typename iterator_traits<Iterator>::value_type value_type;
				typedef typename iterator_traits<Iterator>::difference_type difference_type;
				typedef typename iterator_traits<Iterator>::pointer pointer;
				typedef typename iterator_traits<Iterator>::reference reference;

				// * Default constructor
				reverse_iterator() : iter() {}

				explicit reverse_iterator (Iterator it) : iter(it) {}

				template<typename Iter>
				reverse_iterator(reverse_iterator<Iter> const &rev_it) : iter(rev_it.base()) {}

				reverse_iterator &operator=(const reverse_iterator<Iterator> &rev_it) { iter = rev_it.base(); return *this; }

				// return iterator
				iterator_type base() const { return iter; }

				operator reverse_iterator<const Iterator>() const { return iter; }

				// reference to the element pointed
				reference operator*() const { Iterator tmp = iter; return *--tmp; }

				// pointer to the element pointed
				pointer operator->() const { return &(operator*()); }

				// Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to
				reverse_iterator operator+ (difference_type n) const { return reverse_iterator(iter - n); }

				// decrements the base iterator
				reverse_iterator& operator++() {
					--iter;
					return *this;
				}
				
				reverse_iterator  operator++(int) {
					reverse_iterator tmp(*this);
					--iter;
					return tmp;
				}

				// function decreases by n
				reverse_iterator& operator+= (difference_type n) {
					iter -= n;
					return *this; 
				}

				// applies the binary operator+ on the base iterator and returns a reverse iterator
				reverse_iterator operator- (difference_type n) const { return reverse_iterator(iter + n); }

				// increments the base iterator
				reverse_iterator& operator--() {
					++iter;
					return *this;
				}
				reverse_iterator  operator--(int) {
					reverse_iterator tmp(*this);
					++iter;
			    	return tmp;
				}

				// increases by n the base iterator 
				reverse_iterator& operator-= (difference_type n) {
					iter += n;
					return *this;
				}


				// Accesses the element located n positions
				reference operator[] (difference_type n) const { return *(*this + n); }

		};

		//* Arithmetic operators (+ and -) =================================================================
		template <typename It>
		reverse_iterator<It> operator+ ( typename reverse_iterator<It>::difference_type n, reverse_iterator<It> const &rev_it) {
			return (reverse_iterator<It>(rev_it.base() - n));
		}

		template <typename It1, typename It2>
		typename reverse_iterator<It1>::difference_type operator- (reverse_iterator<It1> const &lhs, reverse_iterator<It2> const &rhs)
		{
			return rhs.base() - lhs.base();
		}

		// *  Relational operators (==, != <, >, <= and >=) =================================================================================================
		template <typename It1, typename It2>
		typename reverse_iterator<It1>::difference_type operator== (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() == rhs.base(); }

		template <typename It1, typename It2>
		bool operator!= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return !(lhs.base() == rhs.base()); }

		template <typename It1, typename It2>
		bool operator<  (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() > rhs.base(); }
  
		template <typename It1, typename It2>
		bool operator<= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() >= rhs.base(); }

		template <typename It1, typename It2>
		bool operator>  (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() < rhs.base(); }

		template <typename It1, typename It2>
		bool operator>= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) { return lhs.base() <= rhs.base(); }

}

#endif
