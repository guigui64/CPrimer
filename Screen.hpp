//
// Created by guillaume on 5/6/16.
//

#ifndef CPRIMER_SCREEN_H
#define CPRIMER_SCREEN_H

#include <iostream>

class Screen {
  // Window_mgr members can access the private members of class Screen
  friend class Window_mgr;
public:
  typedef std::string::size_type pos;
  Screen() = default;   // needed because Screen has another constructor
  Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {
  }
  char get() const   // here, 'const' means that the content of Screen cannot be changed
                     // (except for mutable members)
  {
    return contents[cursor];
  }                                        // implicitly inline
  inline char get(pos ht, pos wd) const;   // explicitly inline
  Screen &move(pos r, pos c);              // can be made inline later
  Screen &set(char);
  Screen &set(pos, pos, char);
  // display overloaded on whether the object is const or not
  // the first one is not const so that it can return a non const object
  // and allow to do screen.display().set('#') for instance
  // but it cannot be called on a const Screen
  Screen &display(std::ostream &os) { do_display(os); return *this; }
  // the second one is const and will be called for a const Screen
  const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
  // function to do the work of displaying a Screen
  void do_display(std::ostream &os) const { os << contents; }
  mutable size_t access_ctr;   // may change even in a const object
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

inline                              // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
  pos row = r * width;   // compute the row location
  cursor = row + c;      // move cursor to the column within that row
  return *this;          // return this object as an lvalue
}
char Screen::get(pos r, pos c) const // declared as inline in the class
{
  ++access_ctr;               // change a mutable member
  //++cursor;                   // doesn't compile !
  pos row = r * width;        // compute row location
  return contents[row + c];   // return character at the given column
}

inline Screen &Screen::set(char c)
{
  contents[cursor] = c;   // set the new value at the current cursor location
  return *this;           // return this object as an lvalue
}
inline Screen& Screen::set(pos r, pos col, char ch)
{
  contents[r*width + col] = ch;   // set specified location to given value
  return *this;
}

#endif //CPRIMER_SCREEN_H
