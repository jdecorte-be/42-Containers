#include <iostream>
#include <memory>
#include <vector>
#include "containers/vector.hpp"
#include "containers/map.hpp"
#include "containers/stack.hpp"

#include <algorithm>
#include <map>
#include <list>
#include <string>
#include <stack>
#include <time.h>
#include <sys/time.h>

#define NAMESPACE ft // change to STD if you want to compare with the STL


time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, NULL);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

void print_time(time_t start)
{
	time_t second = timer();
	std::cout << "Time = " << second - start << "ms" << std::endl;
}

int main()
{
	/* ---------------------------------------------------- */
	/*                                                      */
	/*                        VECTOR		                */
	/*                                                      */
	/* ---------------------------------------------------- */
	std::cout << "VECTOR" << std::endl << std::endl;
	{
		time_t start = timer();
		std::cout << "~~~~TEST WITH INT~~~~~" << std::endl;
		NAMESPACE::vector<int> a;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----CAPACITY----" << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----PUSH_BACK + operator[] + RESERVE----" << std::endl;
		int j = 1;
		for (int i = 0; i < 30; i++)
		{
			a.push_back((j += 3) % 2 ? j : -j);
			std::cout << "Index " << i << " : value = " << a[i] << std::endl;
		}
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----CAPACITY----" << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----RESERVE----" << std::endl;
		a.reserve(50);
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----CAPACITY----" << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << "----AT----" << std::endl;
		std::cout << a.at(5) << std::endl;
		std::cout << a.at(15) << std::endl;
		std::cout << "----FRONT----" << std::endl;
		std::cout << a.front() << std::endl;
		std::cout << "----BACK----" << std::endl;
		std::cout << a.back() << std::endl;
		std::cout << "----COPY_CONSTRUCTOR----" << std::endl;
		NAMESPACE::vector<int> b(a);
		std::cout << "----ASSIGN----" << std::endl;
		std::cout << "before : size = " << a.size() << " && capacity = " << a.capacity() << std::endl;
		a.assign(10, 400);
		std::cout << "after : size = " << a.size() << " && capacity = " << a.capacity() << std::endl;
		std::cout << "----CLEAR----" << std::endl;
		a.clear();
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----OPERATOR=----" << std::endl;
		a = b;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----POP_BACK + RESIZE----" << std::endl;
		for (int i = 0; i < 20; i++)
		{
			a.pop_back();
		}
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << a.at(i) << std::endl;
		}
		std::cout << "----INSERT + BEGIN + END----" << std::endl;
		std::cout << "lets remplace the value of the index 0 by 900" << std::endl;
		a.insert(a.begin(), 900);
		std::cout << "Index " << 0 << " : value = " << a[0] << std::endl;
		std::cout << "lets copy b in the end of a by using insert" << std::endl;
		a.insert(a.end(), b.begin(), b.end());
		std::cout << "lets add 5 x 200 to the result" << std::endl;
		a.insert(a.end(), 5, 200);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << a[i] << std::endl;
		}
		std::cout << "----ERASE + BEGIN + END----" << std::endl;
		std::cout << "lets remove the end element" << std::endl;
		a.erase(a.end() - 1);
		std::cout << "lets remove the two first elements" << std::endl;
		NAMESPACE::vector<int>::iterator it = a.begin();
		it = it + 2;
		a.erase(a.begin(), it);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << a.at(i) << std::endl;
		}
		std::cout << "----SWAP----" << std::endl;
		a.swap(b);
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << a.at(i) << std::endl;
		}
		std::cout << "----OPERATORS----" << std::endl;
		std::cout << "a == b : "<< (a == b) << std::endl;
		std::cout << "a != b : "<< (a != b) << std::endl;
		std::cout << "a > b : "<< (a > b) << std::endl;
		std::cout << "a < b : "<< (a < b) << std::endl;
		std::cout << "~~~~MINI TEST WITH CONST CHAR *~~~~" << std::endl;
		std::cout << "----CONSTRUCTOR WITH VALUE----" << std::endl;
		NAMESPACE::vector<const char *> c(4, "coucou");
		std::cout << "----CONSTRUCTOR WITH ITERATORS----" << std::endl;
		NAMESPACE::vector<const char *> d(c.begin(), c.end());
		for (unsigned int i = 0; i < d.size(); i++)
		{
			std::cout << "Index " << i << " : value = " << d[i] << std::endl;
		}
		std::cout << "----TIME----" << std::endl;
		print_time(start);
	}

	/* ---------------------------------------------------- */
	/*                                                      */
	/*                      STACK                           */
	/*                                                      */
	/* ---------------------------------------------------- */
	std::cout << "STACK" << std::endl << std::endl;
	{
		time_t start = timer();
		NAMESPACE::stack<int> a;
		std::cout << "~~~TEST WITH INT :~~~" << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----PUSH----" << std::endl;
		for (int i = 0; i < 30; i++)
		{
			a.push(i * 3);
			std::cout << "at index " << i << " : value = " << i * 3 << std::endl;
		}
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----TOP----" << std::endl;
		std::cout << a.top() << std::endl;
		std::cout << "----POP----" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			a.pop();
		}
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----TOP----" << std::endl;
		std::cout << a.top() << std::endl;
		NAMESPACE::stack<float> b;
		std::cout << std::endl;
		std::cout << "~~~TEST WITH FLOAT :~~~" << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << b.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << "----PUSH----" << std::endl;
		float f = -0.5f;
		for (int i = 0; i < 30; i++)
		{
			b.push(f);
			std::cout << "at index " << i << " : value = " << f << std::endl;
			f += 0.6f;
		}
		std::cout << "----EMPTY----" << std::endl;
		std::cout << b.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << "----TOP----" << std::endl;
		std::cout << b.top() << std::endl;
		std::cout << "----POP----" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			b.pop();
		}
		std::cout << "----SIZE----" << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << "----TOP----" << std::endl;
		std::cout << b.top() << std::endl;
		std::cout << "----TIME----" << std::endl;
		print_time(start);
	}

	/* ---------------------------------------------------- */
	/*                                                      */
	/*                        MAP                     		*/
	/*                                                      */
	/* ---------------------------------------------------- */	
	std::cout << "MAP" << std::endl << std::endl;
	{
		time_t start = timer();
		std::cout << "----DEFAULT CONSTRUCTOR----" << std::endl;
		NAMESPACE::map<int, float> a;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----OPERATOR[] + INSERT----" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << a[i] << std::endl;
		}
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----OPERATOR[] + INSERT----" << std::endl;
		a.insert(NAMESPACE::make_pair(6, 0.35f));
		std::cout << "at the index 6, there is the value " << a[6] << std::endl;
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----COPY CONSTRUCTOR----" << std::endl;
		NAMESPACE::map<int, float> b(a);
		std::cout << "----CLEAR----" << std::endl;
		a.clear();
		std::cout << "----EMPTY----" << std::endl;
		std::cout << a.empty() << std::endl;
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----SWAP----" << std::endl;
		a.swap(b);
		std::cout << "----SIZE----" << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "----COUNT----" << std::endl;
		std::cout << "is 6th index existing ? " << a.count(6) << std::endl;
		std::cout << "is 98th index existing ? " << a.count(98) << std::endl;
		std::cout << "----CLEAR----" << std::endl;
		a.clear();
		std::cout << "----INSERT----" << std::endl;
		float f = 1.0f;
		int ran;
		srand(8500);
		for (int i = 0; i < 20; i++)
		{
			ran = rand() % 10000;
			a.insert(a.begin(), NAMESPACE::make_pair(ran, f));
			f += 1.5f;
			std::cout << "at index " << ran << " : value = " << a[ran] << std::endl;
		}
		std::cout << "----CONSTRUCTOR WITH ITERATORS + BEGIN + END----" << std::endl;
		NAMESPACE::map<int, float> c(a.begin(), a.end());
		NAMESPACE::map<int, float>::iterator it = c.begin();
		for (unsigned int i = 0; i < c.size(); i++)
		{
			std::cout << "at index " << it->first << " : value = " << c[it->first] << std::endl;
			it++;
		}
		std::cout << "----CLEAR----" << std::endl;
		a.clear();
		std::cout << "----INSERT----" << std::endl;
		a.insert(c.begin(), c.end());
		it = a.begin();
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "at index " << it->first << " : value = " << a[it->first] << std::endl;
			it++;
		}
		std::cout << "----ERASE + FIND----" << std::endl;
		std::cout << "lets erase first element" << std::endl;
		a.erase(a.begin());
		std::cout << "lets erase element 6706" << std::endl;
		a.erase(6706);
		std::cout << "lets erase element 9445 to end" << std::endl;
		a.erase(a.find(9445), a.end());
		it = a.begin();
		for (unsigned int i = 0; i < a.size(); i++)
		{
			std::cout << "at index " << it->first << " : value = " << a[it->first] << std::endl;
			it++;
		}
		std::cout << "----UPPER_BOUND----" << std::endl;
		it = a.upper_bound(8429);
		std::cout << "at index " << it->first << " : value = " << a[it->first] << std::endl;
		std::cout << "----LOWER_BOUND----" << std::endl;
		it = a.lower_bound(4427);
		std::cout << "at index " << it->first << " : value = " << a[it->first] << std::endl;
		std::cout << "----EQUAL_RANGE----" << std::endl;
		NAMESPACE::pair<NAMESPACE::map<int, float>::iterator, NAMESPACE::map<int, float>::iterator> eq = a.equal_range(4427);
		std::cout << "lower_bound at index " << eq.first->first << " : value = " << a[eq.first->first] << std::endl;
		std::cout << "upper_bound at index " << eq.second->first << " : value = " << a[eq.second->first] << std::endl;
		std::cout << "----RBEGIN + REND----" << std::endl;
		NAMESPACE::map<int, float>::reverse_iterator rit = a.rbegin(), rite = a.rend();
		while (rit != rite)
		{
			std::cout << "at index " << rit->first << " : value = " << a[rit->first] << std::endl;
			rit++;
		}
		std::cout << "----OPERATORS----" << std::endl;
		std::cout << "a == c : "<< (a == c) << std::endl;
		std::cout << "a != c : "<< (a != c) << std::endl;
		std::cout << "a >= c : "<< (a >= c) << std::endl;
		std::cout << "a < c : "<< (a < c) << std::endl;
		std::cout << "----TIME----" << std::endl;
		print_time(start);
	}
	system("leaks a.out");
}