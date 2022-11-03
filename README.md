
<h1 align="center">
	📖 Containers
</h1>

<p align="center">
	<b><i>Implementation C++ STL containers</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jdecorte-be/42-Containers?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/jdecorte-be/42-Containers?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jdecorte-be/42-Containers?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jdecorte-be/42-Containers?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jdecorte-be/42-Containers?color=green" />
</p>

# Summary

This is a project to re-implement some `C++ STL Containers` to understand them.

Some requirements for this project are as follow:

Re-implement (The documents below are written in Korean.)

### Mandatory

+ [`std::vector`](documents/vector.md)
+ [`std::map`](documents/map.md)
+ [`std::stack`](documents/stack.md)
+ [`std::iterators_traits`](documents/reverse_iterator.md)
+ [`std::reverse_iterator`](documents/iterator_traits.md)
+ [`std::enable_if`](documents/enable_if.md)
+ [`std::is_integral`](documents/is_integral.md)
+ [`std::equal`](documents/equal.md) and/or [`std::lexicographical_compare`](documents/lexicographical_compare.md)
+ [`std::pair`](documents/pair.md)
+ [`std::make_pair`](documents/make_pair.md)

### Bonus

+ [`std::set`](documents/set.md)

# What is STL? <sup>[1]

> The `Standard Template Library (STL)` is a set of `C++ template classes` to provide common programming data structures and functions such as `list`, `stack`, `vector`, etc <sup>[1]

> `STL` has four components
> + [Algorithms](#algorithms)
> + [Containers](#containers)
> + [Functions(Functor)](#functionsfunctor)
> + [Iterators](#iterators)

This project is designed to implement a few containers, functions, and iterators in the C++98.

## Algorithms

> The header algorithm defines a collection of functions especially designed to be used on ranges of elements. They act on containers and provide means for various operations for the contents of the containers. <sup>[1]

> Algorithms
>	+ Sorting
> 	+ Searching
> 	+ partition
> 	+ etc.

## Containers

> Containers or container classes store objects and data. There are in total 7 standard "first-class" container classes and 3 container adaptor classes and only seven header files that provide access to these containers or container adaptors. <sup>[1]

| sequence containers                                                     | container adaptors                                       | associative containers                                                               | unordered associative containers`(c++11)`                        |
| ----------------------------------------------------------------------- | -------------------------------------------------------- | ------------------------------------------------------------------------------------ | ---------------------------------------------------------------- |
| implement data structures which can be accessed in a sequential manner. | provide a different interface for sequential containers. | implement sorted data structures that can be quickly searched(O(long n) complexity). | implement unordered data structures that can be quickly searched |
| vector                                                                  | queue                                                    | set                                                                                  | unordered_set `(c++11)`                                          |
| list                                                                    | priority queue                                           | multiset                                                                             | unordered_multiset `(c++11)`                                     |
| deque                                                                   | stack                                                    | map                                                                                  | unordered_map `(c++11)`                                          |
| arrays`(c++11)`                                                         | multimap                                                 |                                                                                      | unordered_multimap `(c++11)`                                     |
| forward lists`(c++11)`                                                  |

> Flowchart of Adaptive containers and Unordered Containers <sup>[1]
> 
>![Flowchart of Adaptive containers and Unordered Containers](https://media.geeksforgeeks.org/wp-content/uploads/20191111161536/Screenshot-from-2019-11-11-16-13-18.png)
>
> Flowchart of Sequence containers and Ordered Containers <sup>[1]
> 
>![Flowchart of Sequence containers and Ordered Containers](https://media.geeksforgeeks.org/wp-content/uploads/20191111161627/Screenshot-from-2019-11-11-16-15-07.png)

## Functions(Functor)

> The STL includes classes that overload the function call operator. Instances of such classes are called function objects or functors. Functors allow the working of the associated function to be customized with the help of parameters to be passed. <sup>[1]

## Iterators

> As the name suggests, iterators are used for working upon a sequence of values. They are the major feature that allow generality in STL. <sup>[1]
# Reference

| index                                                                           | title                                                                                                                 | author        | last modified | accessed     | url status |
| ------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------- | ------------- | ------------- | ------------ | ---------- |
| [1](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/?ref=lbp) | [The C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/?ref=lbp) | GeeksforGeeks | 19 Nov, 2021  | 15 May, 2022 | ok         |
