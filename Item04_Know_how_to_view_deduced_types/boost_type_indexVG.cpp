/*
 * Key idea:
 *
 *   It is possible to produce accurate type information using Boost.TypeIndex.
 *
 */
#include <iostream>
#include <typeinfo>
#include <vector>

#include <boost/type_index.hpp>
  using std::cout;
  using boost::typeindex::type_id_with_cvr;

class Widget {};

template<typename T>
void f(const T& param)
{

  // show T
  cout << "T =     "
       << type_id_with_cvr<T>().pretty_name()
       << '\n';

  // show param's type
  cout << "param = "
       << type_id_with_cvr<decltype(param)>().pretty_name()
       << '\n';
}

std::vector<Widget> createVec()    // factory function
{
    std::vector<Widget> vw;
    Widget w;
    vw.push_back(w);
    return vw;
}

int main()
{

    const auto vw0 = createVec();        // init vw w/factory return
    auto vw = createVec();        // init vw w/factory return
    auto& vw1(vw); 
    auto&& vw2(createVec()); 

    cout << "param0 = "
       << type_id_with_cvr<decltype(vw0)>().pretty_name()
       << '\n';
    cout << "param1 = "
       << type_id_with_cvr<decltype(vw)>().pretty_name()
       << '\n';
    cout << "param2 = "
       << type_id_with_cvr<decltype(vw1)>().pretty_name()
       << '\n';
    cout << "param3 = "
         << type_id_with_cvr<decltype(vw2)>().pretty_name()
         << " | " << type_id_with_cvr<decltype(vw2)>().name()
         << '\n';

    if (!vw.empty()) {
      f(&vw[0]);                        // call f
      // ...
    }
}
