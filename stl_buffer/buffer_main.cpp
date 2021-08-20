// rvalue-references-move-semantics.cpp

#include "MemoryBlock.h"
#include <vector>
#include <boost/type_index.hpp>
  using boost::typeindex::type_id_with_cvr;

using namespace std;

template<typename T>
//void printVec( T&& v)
void printVec(const T& v)
{
  cout << "\n printing vec" << endl;
  // show T
  cout << "T="
       << type_id_with_cvr<T>().pretty_name()
       << ' ';

  // show param's type
  cout << " | param="
       << type_id_with_cvr<decltype(v)>().pretty_name()
       << '\n';

  for (const auto &elt : v)
  {
    cout << elt.size() << endl;
  }
}

int main()
{
   // Create a vector object and add a few elements to it.
   vector<MemoryBlock> v;
   v.reserve(4);
   cout << "v.size=" << v.size() << endl;
   cout << "v.capacity=" << v.capacity() << endl;
   v.push_back(MemoryBlock(25));

   cout << "\nINSERT val" << endl;
   MemoryBlock mb(65);
   v.push_back(mb);
   //v.push_back(std::move(mb));

   cout << "\nINSERT mov" << endl;
   v.push_back(MemoryBlock(75));
   
   printVec(v);

   cout << "\n INSERT elment" << endl;
   // Insert a new element into the second position of the vector.
   v.insert(v.begin() + 1, MemoryBlock(50));
   
   cout << "\nINSERT force resize" << endl;
   v.push_back(MemoryBlock(100));
   cout << "v.size=" << v.size() << endl;
   cout << "v.capacity=" << v.capacity() << endl;

   printVec(v);

   cout << "\nresize to 8" << endl;
   v.resize(8, MemoryBlock(1));
   cout << "v.size=" << v.size() << endl;
   cout << "v.capacity=" << v.capacity() << endl;

   printVec(v);

   cout << "\nDESTROY" << endl;
}
