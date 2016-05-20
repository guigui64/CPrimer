#include <iostream>
#include "Screen.hpp"
#include "Window_mgr.hpp"

using namespace std;

int main()
{
  Window_mgr manager;
  Screen firstScreen = manager.getScreen(0);
  firstScreen.move(4,0).set('#').display(cout);

  std::cout << "---------- CLEARING SCREEN ----------" << std::endl;
  manager.clear(0);
  manager.getScreen(0).display(cout);

  return 0;
}
