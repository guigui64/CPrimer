//
// Created by guillaume on 5/6/16.
//

#ifndef CPRIMER_WINDOW_MGR_H
#define CPRIMER_WINDOW_MGR_H


#include <vector>
#include "Screen.hpp"

class Window_mgr {
public:
  const Screen &getScreen(size_t n) const {
    return screens.at(n);
  }
private:
  // Screens this Window_mgr is tracking
  // by default, a Window_mgr has one standard sized blank Screen
  std::vector<Screen> screens {Screen(24, 80, ' ')};

};


#endif //CPRIMER_WINDOW_MGR_H
