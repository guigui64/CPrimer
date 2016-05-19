#include <iostream>
#include "Screen.hpp"
#include "Window_mgr.hpp"

using namespace std;

int main() {
  Window_mgr manager;
  Screen firstScreen = manager.getScreen(0);

  firstScreen.move(4,0).set('#');

  cout << firstScreen.get() << endl;

  return 0;
}
