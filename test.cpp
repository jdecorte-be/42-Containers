#include "containers/vector.hpp"
#include <iostream>
#include <iostream>
#include <vector>


int		main(void)
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  // myvector.insert (it,2,300);

  // // "it" no longer valid, get a new one:
  // it = myvector.begin();

  // ft::vector<int> anothervector (2,400);
  // myvector.insert (it+2,anothervector.begin(),anothervector.end());

  // int myarray [] = { 501,502,503 };
  // myvector.insert (myvector.begin(), myarray, myarray+3);

  // std::cout << "myvector contains:";
  // for (it=myvector.begin(); it<myvector.end(); it++)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';

  return 0;
}

