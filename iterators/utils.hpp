#ifndef UTILS_HPP
#define UTILS_HPP

namespace detail {

template<class It>
typename std::iterator_traits<It>::difference_type 
    do_distance(It first, It last, std::input_iterator_tag)
{
    typename std::iterator_traits<It>::difference_type result = 0;
    while (first != last) {
        ++first;
        ++result;
    }
    return result;
}
 
template<class It>
typename std::iterator_traits<It>::difference_type 
    do_distance(It first, It last, std::random_access_iterator_tag)
{
    return last - first;
}
 
} // namespace detail

namespace ft
{
    template<class It>
    typename std::iterator_traits<It>::difference_type distance(It first, It last)
    {
        return detail::do_distance(first, last,
                                typename std::iterator_traits<It>::iterator_category());
    }
}


#endif // !UTILS_HPP