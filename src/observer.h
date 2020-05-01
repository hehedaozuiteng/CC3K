#ifndef _OBSERVER_H_
#define _OBSERVER_H_

// DO NOT MODIFY THIS FILE!

template < typename NoticceType> class Subject;
class Cell;

template < typename NoticceType> class Observer {
 public:
  virtual void notify(Subject< NoticceType> &whoFrom) = 0; // pass the Subject that called the notify method
  virtual ~Observer() = default;
};
#endif

