/*
 * Key idea:
 *
 *   It is possible to produce accurate type information using Boost.TypeIndex.
 *
 */
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

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
       << ' ';

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

template<typename T>
void pur(std::string name,  T&& param)
{
  cout << name << " (PARM)"
       << " | T = "
       << type_id_with_cvr<T>().pretty_name()
       << ' ';
  cout << " | param = "
       << type_id_with_cvr<decltype(param)>().pretty_name()
       << '\n';

  cout << name << " (FORW)"
       << " | T = "
       << type_id_with_cvr<T>().pretty_name()
       << ' ';
  cout << " | param = "
       << type_id_with_cvr<decltype(std::forward<T>(param))>().pretty_name()
       << '\n';

//local variables
auto  val = param;
  cout << name << " (AUTO)"
       << " | T = "
       << type_id_with_cvr<T>().pretty_name()
       << ' ';
  cout << " | param = "
       << type_id_with_cvr<decltype(val)>().pretty_name()
       << '\n';

auto decl2(std::forward<T>(param));
  cout << name << " (AFOR)"
       << " | T = "
       << type_id_with_cvr<T>().pretty_name()
       << ' ';
  cout << " | param = "
       << type_id_with_cvr<decltype(decl2)>().pretty_name()
       << '\n';

T&& decl1(std::forward<T>(param));
  cout << name << " (UREF)"
       << " | T = "
       << type_id_with_cvr<T>().pretty_name()
       << ' ';
  cout << " | param = "
       << type_id_with_cvr<decltype(decl1)>().pretty_name()
       << '\n'
       << '\n';
}


int main()
{

    auto vw = createVec();        // init vw w/factory return
    const auto vw0 = createVec();        // init vw w/factory return
    auto& vw1(vw); 
    auto&& vw2(createVec()); 

    cout << "param  = "
       << type_id_with_cvr<decltype(vw)>().pretty_name()
       << '\n';
    cout << "param0 = "
       << type_id_with_cvr<decltype(vw0)>().pretty_name()
       << '\n';
    cout << "param1 = "
       << type_id_with_cvr<decltype(vw1)>().pretty_name()
       << '\n';
    cout << "param2 = "
         << type_id_with_cvr<decltype(vw2)>().pretty_name()
         << " | " << type_id_with_cvr<decltype(vw2)>().name()
         << '\n';

    if (!vw.empty()) {
      f(&vw[0]);                        // call f
      // ...
    }
    pur("RV val", std::vector<Widget>() );
    pur("RV ptr", new std::vector<Widget>() );
    pur("LV val", vw );
    pur("LV cva", vw0 );
    // pur("RV", std::vector<Widget>() );
}
