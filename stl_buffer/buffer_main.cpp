// rvalue-references-move-semantics.cpp

#include "MemoryBlock.h"
#include <vector>

using namespace std;

int main()
{
   // Create a vector object and add a few elements to it.
   vector<MemoryBlock> v;
   v.reserve(5);
   v.push_back(MemoryBlock(25));

   cout << "\nINSERT val" << endl;
   MemoryBlock mb(65);
   v.push_back(mb);
   //v.push_back(std::move(mb));

   cout << "\nINSERT mov" << endl;
   v.push_back(MemoryBlock(75));
   
   cout << "\n printing vec" << endl;
   for(const auto& elt : v)
   {
     cout << elt.size() << endl;
   }

   cout << "\n INSERT elment" << endl;
   // Insert a new element into the second position of the vector.
   v.insert(v.begin() + 1, MemoryBlock(50));
   
   cout << "\n printing vec" << endl;
   for(const auto& elt : v)
   {
     cout << elt.size() << endl;
   }

   cout << "\nDESTROY" << endl;
}
