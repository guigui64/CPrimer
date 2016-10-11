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

// Example of a class with static members
class Account {
public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; } // static member defined in-class
  static void rate(double);
private:
  std::string owner;
  double amount;
  static constexpr int ID = 1; // static member defined in-class
  static double interestRate;
  static double initRate();
};
// Defining static members outside the class
double Account::interestRate = initRate();
inline double Account::initRate() { return 2.5/100; }
void Account::rate(double newRate) {
  interestRate = newRate;
}

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

  double r;
  r = Account::rate(); // access a static member using the scope operator
  Account ac1;
  Account *ac2 = &ac1;
  // equivalent ways to call the static member rate fucntion
  r = ac1.rate();  // through an Account object or reference
  r = ac2->rate(); // though a pointer to an Account object
  std::cout << r << std::endl;
  ac1.calculate();

  std::cout << "-------- IO LIBRARY --------" << std::endl;
  int ival;
  std::cin >> ival;
  std::cout << (cin.fail() ? "FAIL !" : std::to_string(ival)) << std::endl;

  return 0;
}
