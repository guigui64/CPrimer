#include <iostream>
#include "Screen.h"
#include "Window_mgr.h"

using namespace std;

int main() {
  Window_mgr manager;
  Screen firstScreen = manager.getScreen(0);

  firstScreen.move(4,0).set('#');

  cout << firstScreen.get() << endl;

  return 0;
}
