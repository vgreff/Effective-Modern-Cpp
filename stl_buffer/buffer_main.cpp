// constructing unordered_sets
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm> 
#include <functional>
#include <iostream>


template<class T>
T cmerge (T a, T b) { T t(a); t.insert(b.begin(),b.end()); return t; }

template<class T, class C>
std::ostream& printCol(std::ostream& out, T&& title,  C&& col)
{
  out << title << " contains: ";
  for (const auto& x: col) 
  {
      out << " " << x;
  }
  out << std::endl;
  return out;
}

int main ()
{
  std::unordered_set<std::string> first;                                // empty
  std::unordered_set<std::string> second ( {"red","green","blue"} );    // init list
  std::unordered_set<std::string> third ( {"orange","pink","yellow"} ); // init list
  std::unordered_set<std::string> fourth ( second );                    // copy
  std::unordered_set<std::string> fifth ( cmerge(third,fourth) );       // move
  std::unordered_set<std::string> sixth ( fifth.begin(), fifth.end() ); // range

  printCol(std::cout,"sixth", sixth);

std::string search("orange");
auto found = std::find_if (sixth.begin(), sixth.end(), [&search](auto str) { return str == search; });
if (found != sixth.end())
{
    std::cout << "found=" << *found;
    std::cout << std::endl;
}
else
{
    std::cout << "NOT found!" << std::endl;
}

std::vector<std::string> myvector (sixth.begin(), sixth.end());

//std::sort (myvector.begin(), myvector.end(),  [] (auto lhs, auto rhs) { return lhs > rhs; });
//std::sort (myvector.begin(), myvector.end(),  [] (auto lhs, auto rhs) { return lhs < rhs; });
//std::sort (myvector.begin(), myvector.end(),  std::less<>() );
std::sort (myvector.begin(), myvector.end(),  std::greater<>() );


  //std::cout << "sixth contains:";
  //for (const std::string& x: myvector) std::cout << " " << x;
  //std::cout << std::endl;

    printCol(std::cout,"set", sixth);
    printCol(std::cout, "Vector sorted", myvector);
    printCol(std::cout,123.45, myvector);

  return 0;
}