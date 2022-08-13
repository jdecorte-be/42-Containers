#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator_traits/
// https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/

#include <iterator>

namespace ft
{
    template <class Iterator>
        struct iterator_traits
        {
            public :
                typedef typename Iterator::difference_type difference_type;
                typedef typename Iterator::value_type value_type;
                typedef typename Iterator::pointer pointer;
                typedef typename Iterator::reference reference;
                typedef typename Iterator::iterator_category iterator_category;
        };
    template <class T>
        struct iterator_traits<T*>
        {
            public :
                typedef std::ptrdiff_t difference_type;
                typedef T value_type;
                typedef T* pointer;
                typedef T& reference;
                typedef std::random_access_iterator_tag iterator_category;
        };
    template <class T>
        struct iterator_traits<T* const>
        {
            public :
                typedef std::ptrdiff_t difference_type;
                typedef T value_type;
                typedef const T* pointer;
                typedef const T& reference;
                typedef std::random_access_iterator_tag iterator_category;
        };
}

#endif
