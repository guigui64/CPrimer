//
// Created by guillaume on 5/6/16.
//

#ifndef CPRIMER_WINDOW_MGR_H
#define CPRIMER_WINDOW_MGR_H


#include <vector>
#include "Screen.hpp"

class Window_mgr
{
public:
  // location ID for each screen on the window
  using ScreenIndex = std::vector<Screen>::size_type;
  // get the screen correspondign to the given index
  const Screen &getScreen(ScreenIndex n) const { return screens.at(n); }
  // reset the screen at the given position to blanks
  void clear(ScreenIndex);
  // add a Screen to the window and returns its index
  ScreenIndex addScreen(const Screen&);
private:
  // Screens this Window_mgr is tracking
  // by default, a Window_mgr has one standard sized blank Screen
  std::vector<Screen> screens {Screen(24, 80, ' ')};

};
void Window_mgr::clear(ScreenIndex index)
{
  // s is a reference to the Screen we want to clear
  Screen &s = screens[index];
  // We can access the private members of s because Window_mgr is friend with
  // Screen
  s.contents = std::string(s.height * s.width, ' ');
}
// return type is seen before we're in the scope of Window_mgr
// => We need to specify the scope of ScreenIndex
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &screen)
{
  screens.push_back(screen);
  return screens.size() - 1;
}


#endif //CPRIMER_WINDOW_MGR_H
