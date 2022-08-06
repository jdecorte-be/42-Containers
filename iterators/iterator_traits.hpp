#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator_traits/
// https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/

#include <iterator>

namespace ft
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Category, class T>
        struct iterator
        {
            typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
            typedef Category iterator_category;
        };
    template <class Iterator>
        struct iterator_traits
        {
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;
            typedef typename Iterator::iterator_category iterator_category;
        };
    template <class T>
        struct iterator_traits<T*>
        {
            typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
            typedef std::random_access_iterator_tag iterator_category;
        };
    template <class T>
        struct iterator_traits<T* const>
        {
            typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef const T* pointer;
            typedef const T& reference;
            typedef std::random_access_iterator_tag iterator_category;
        };
}

#endif
