#include <iostream>
#include "Screen.hpp"
#include "Window_mgr.hpp"

using namespace std;

class DefaultParameterConstructorClass {
public:
  // defines the default constructor as well as one that takes a string argument
  DefaultParameterConstructorClass(string s = "defaultName") : name(s) {}
  string name;
};

class DelegateConstructorsClass {
public:
  DelegateConstructorsClass(int ival, double dval) : i(ival), j(ival), d(dval) {}
  // delegate constructors :
  DelegateConstructorsClass() : DelegateConstructorsClass(0, 0.0) {}
  DelegateConstructorsClass(int ival) : DelegateConstructorsClass(ival, 0.0) {}
  DelegateConstructorsClass(double dval) : DelegateConstructorsClass(0, dval) {}
  // members :
  int i,j;
  double d;
};

struct AggregateClass {
  // A class is an aggregate if
  // - All of its data members are public
  // - It does not define any constructors
  // - It has no in-class initializers
  // - It has no base classes or virtual functions, which are class-related features
  int ival;
  string s;
};

int main()
{
  Window_mgr manager;
  Screen firstScreen = manager.getScreen(0);
  firstScreen.move(4,0).set('#').display(cout);

  std::cout << "---------- CLEARING SCREEN -----------" << std::endl;
  manager.clear(0);
  manager.getScreen(0).display(cout);

  std::cout << "-- DefaultParameterConstructorClass --" << std::endl;
  DefaultParameterConstructorClass dpc;
  std::cout << dpc.name << std::endl;
  dpc = DefaultParameterConstructorClass("newName");
  std::cout << dpc.name << std::endl;

  AggregateClass ac = {0, "Anna"}; // The order is important !

  return 0;
}
