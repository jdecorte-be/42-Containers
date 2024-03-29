#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <exception>
#include <stdexcept>
#include <string>
#include <limits>
#include <iterator>
# include <iostream>
# include <memory>
# include <limits>

#include "../iterators/reverse_iterator.hpp"
#include "../iterators/random_access_iterator.hpp"
#include "../utils/is_integral.hpp"


namespace ft
{
    template < class T, class Allocator = std::allocator<T> > 
    class vector_base
    {
        public :
            typedef Allocator allocator_type;
            typedef std::allocator_traits<allocator_type> alloc_traits; 
            typedef typename alloc_traits::size_type size_type;
        protected :
            typedef T value_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef typename alloc_traits::difference_type difference_type;
            typedef typename alloc_traits::pointer pointer;
            typedef typename alloc_traits::const_pointer const_pointer;
            typedef pointer iterator;
            typedef const_pointer const_iterator;
    };



    template < class T, class Allocator = std::allocator<T> > 
	class vector
        : public vector_base<T, Allocator>
    {
        private :
            typedef vector_base<T, Allocator> base;

        public :
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename base::reference reference;
            typedef typename base::const_reference const_reference;
            typedef typename base::size_type size_type;
            typedef typename base::difference_type difference_type;
            typedef typename base::pointer pointer;
            typedef typename base::const_pointer const_pointer;
            typedef ft::random_access_iterator<pointer> iterator;
            typedef ft::random_access_iterator<const_pointer> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        private:
            value_type *arr;
            size_type _size;
            size_type _cap;

            allocator_type _alloc;
        public :
            // 
            // Constructor
            // 
            explicit vector (const allocator_type& alloc = allocator_type());
            explicit vector (size_type n, const value_type& val = value_type(),  const allocator_type& alloc = allocator_type());

            template <typename InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0);
            vector (const vector& x);

            ~vector();

            vector& operator= (const vector& x);

            //
            // Iterator
            // 
            iterator begin();
            const_iterator begin() const;

            iterator end();
            const_iterator end() const;

            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;

            reverse_iterator rend();
            const_reverse_iterator rend() const;

            // 
            // Capacity
            // 
            bool empty() const;
            size_type size() const;
            size_type max_size() const;
            void resize(size_type n, value_type val = value_type());
            size_type capacity() const;
            void reserve(size_type n);

            // 
            // Element access
            // 
            reference operator[](size_type n);
            const_reference operator[](size_type n) const;

            reference at(size_type n);
            const_reference at(size_type n) const;

            reference front();
            const_reference front() const;

            reference back();
            const_reference back() const;

            // 
            // Modifiers
            // 
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0);
            void assign(size_type n, const value_type &val);

            void push_back(const value_type &val);
            void pop_back();

            iterator insert(iterator position, const value_type &val);
            void insert(iterator position, size_type n, const value_type &val);

            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0);

            iterator erase(iterator position);
            iterator erase(iterator first, iterator last);

            void swap(vector &x);
            void clear();
    };

    template <class T, class Alloc>
    vector<T, Alloc>::vector(const allocator_type& alloc)
        : arr(NULL), _size(0), _cap(0), _alloc(alloc) {};

    template <class T, class Alloc> 
    vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
        : arr(NULL), _size(0), _cap(0), _alloc(alloc)
    {
        resize(n, val);
    };

    template <class T, class Alloc> 
    template <class InputIterator>
    vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type*)
        :  arr(NULL), _size(0), _cap(0), _alloc(alloc)
    {
        assign(first, last);
    };

    template <class T, class Alloc> 
    vector<T, Alloc>::vector (const vector& x)
        : _size(x._size), _cap(x._cap), _alloc(x._alloc) {
        arr = _alloc.allocate(_cap);
        for(size_type i = 0; i < _size; i++)
            _alloc.construct(&arr[i], x.arr[i]);
    };
    
    template <class T, class Alloc> 
    vector<T, Alloc>::~vector() {
        clear();
        _alloc.deallocate(arr, _cap);
    };

    template <class T, class Alloc> 
    vector<T, Alloc>  &vector<T, Alloc>::operator= (const vector& x) {
        if(this == &x)
            return *this;
        for(size_type i = 0; i < _size; i++)
            _alloc.destroy(&arr[i]);
        _size = x._size;
        _cap = x._cap;
        arr = _alloc.allocate(_cap);

        const_iterator first = x.begin(); const_iterator last = x.end();
        for (size_type i = 0; first != last; ++first)
            _alloc.construct(&arr[i++], *first);
        return *this;
    };

    // 
    // 
    // * Begin =================================================================
    template <class T, class Alloc> 
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin() {
        return arr;
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const {
        return arr;
    }

    // 
    // 
    // * End ====================================================================
    template <class T, class Alloc> 
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end() {
        return arr + _size;
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const {
        return arr + _size;
    }

    // 
    // 
    // * RBegin ====================================================================
    template <class T, class Alloc> 
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin() {
        return reverse_iterator(end());
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const {
        return const_reverse_iterator(end());
    }

    // 
    // 
    // * RBegin ====================================================================
    template <class T, class Alloc> 
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend() {
        return reverse_iterator(begin());
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const {
        return const_reverse_iterator(begin());
    }


    // 
    // Capacity
    // 
    template <class T, class Alloc> 
    bool vector<T, Alloc>::empty() const {
        return _size == 0;
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const {
        return _size;
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const {
        return _alloc.max_size();
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::resize(size_type n, value_type val) {
        if(n > _cap)
            reserve(n);
        if (n < size())
        {
            for (size_type i = n; i < _size ; i++)
                _alloc.destroy(&arr[i]);
        }
        else
        { 
            for (size_type i = _size; i < n ; i++)
                _alloc.construct(&arr[i], val);
        }
        _size = n;
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const {
        return _cap;
    }

    template <class T, class Alloc>    
    void vector<T, Alloc>::reserve(size_type n) {
        if (n > _alloc.max_size())
            throw std::length_error("vector::reserve");
        if (n > _cap)
        {
            value_type *tmp_arr = _alloc.allocate(n);
            if(arr != NULL)
            {
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(&tmp_arr[i], arr[i]);
                for(size_type i = 0; i < n; i++)
                    _alloc.destroy(&arr[i]);
                _alloc.deallocate(arr, _cap); // ?
            }
            arr = tmp_arr;
            _cap = n;
        }
    }


    // 
    // Element access
    // 
    template <class T, class Alloc> 
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n) {
        return arr[n];
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const {
        return arr[n];
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n) {
        if(n >= _size)
            throw std::out_of_range("vector");
        return arr[n];
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
        if(n >= _size)
            throw std::out_of_range("vector");
        return arr[n];
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::reference vector<T, Alloc>::front() {
        return arr[0];
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const {
        return arr[0];
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::reference vector<T, Alloc>::back() {
        return arr[_size - 1];
    }

    template <class T, class Alloc> 
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const {
        return arr[_size - 1];
    }


    // 
    // Modifiers
    // 
    template <class T, class Alloc> 
    template <class InputIterator>
    void vector<T, Alloc>::assign(InputIterator first, InputIterator last, 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type*) {
        clear();
        for (InputIterator i = first; i != last; ++i)
            push_back(*i);
    }

    template <class T, class Alloc> 
    void vector<T, Alloc>::assign(size_type n, const value_type &val) {
        clear();
        while(n--)
            push_back(val);  
    }

    template <class T, class Alloc> 
    void vector<T, Alloc>::push_back(const value_type &val) {
        resize(_size + 1, val);
    }

    template <class T, class Alloc> 
    void vector<T, Alloc>::pop_back() {
        _alloc.destroy(&arr[_size - 1]);
        _size--;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, const value_type &val) {
		size_type		off = position - this->begin();
		this->insert(position, 1, val);
		return (iterator(arr + off));
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val) {
		size_type		off = position - this->begin();

		if (_size + n > _cap)
		{
			if (_size + n > _cap * 2)
				this->reserve(_size + n);
			else if (_cap > 0)
				this->reserve(_cap * 2);
			else
				this->reserve(1);
		}

		for (size_type i = 0 ; i < n ; i++)
			_alloc.construct(arr + _size + i, val);
		for (int i = _size - 1 ; i >= 0 && i >= (int)off ; i--)
			arr[i + n] = arr[i];
		for (size_type i = off ; i < off + n ; i++)
			arr[i] = val;
		_size = _size + n;
    }

    template <class T, class Alloc> 
    template <class InputIterator>
    void vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type*) {
        difference_type pos = position - begin();
        difference_type n = std::distance(first, last);
        reserve(_size + n);

        for(difference_type i = _size - 1; i >= pos; i--)
        {
            _alloc.construct(&arr[i + n], arr[i]);
            _alloc.destroy(&arr[i]);
        }

        for(InputIterator ite = first; ite != last; ++ite)
            _alloc.construct(&arr[pos++], *ite);
        _size += n;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position) {
        size_type pos = (position - begin());

        for(size_type i = pos; i < _size - 1; i++)
        {
            _alloc.construct(&arr[i], arr[i + 1]);
            _alloc.destroy(&arr[i + 1]);
        }
        _size--;
        _alloc.destroy(&arr[_size - 1]);
        return position;
    }

    
    template <class T, class Alloc> 
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last) {
        size_type pos = last - first;

        while(pos--)
            erase(first);
        return first;
    }

    template <class T, class Alloc> 
    void vector<T, Alloc>::swap(vector &x) {
        value_type *arr_tmp = x.arr;
        size_type size_tmp = x._size;
        size_type cap_tmp = x._cap;

        x.arr = arr;
        x._size = _size;
        x._cap = _cap;

        arr = arr_tmp;
        _size = size_tmp;
        _cap = cap_tmp;
    }

    template <class T, class Alloc> 
    void vector<T, Alloc>::clear() {
        if(arr != NULL)
        {
            for(size_type i = 0; i < _size; i++)
                _alloc.destroy(&arr[i]);
            _size = 0;
        }
    }

    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1) {
            if (!(*first1 == *first2))
            return false;
            ++first1; ++first2;
        }
        return true;
    }

    // * Relational operators
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        if(lhs.size() != rhs.size()) return false;
        return equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        if(lhs.size() != rhs.size()) return true;
        return !(equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

};

#endif // !VECTOR_HPP