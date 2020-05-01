#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <iostream>

using namespace std;

/* A note on InfoType and StateType:

   We have separated the collection of fields into two parts:  its Info
   and its State.

   Info is for the parts of the subjject inherent to what it is:  its position
   and its colour.

   State is for the parts of the subject that, when changed, trigger
   notifications.  This is the information that the Observer "gets" when it
   calls getState on the subject.  It comprises the type of state, a direction,
   and a colour.  For more details, see state.h.
*/

// DO NOT MODIFY THIS FILE!


template <typename NoticceType> class Observer;

template <typename NoticeType> class Subject {
	
	NoticeType notice;
protected:
	void setNotice(NoticeType newS);
public:
	std::vector<Observer<NoticeType>*> observers;
	

	void attach(Observer< NoticeType> *o);
	std::vector<Observer<NoticeType>*> release();
	void notifyObservers();
	NoticeType getNotice() const;
};

template <typename NoticeType>
void Subject<NoticeType>::attach(Observer<NoticeType> *o) {
	observers.emplace_back(o);
}

template < typename NoticeType>
void Subject<NoticeType>::notifyObservers() {
	
	for (auto &ob : observers) {
		ob->notify(*this);

	}
}

template < typename NoticeType>
std::vector<Observer<NoticeType>*> Subject<NoticeType>::release() {
	std::vector<Observer<NoticeType>*> temp = observers;
	observers.clear();
	return observers;
}

template <typename NoticeType>
void Subject<NoticeType>::setNotice(NoticeType newS) { notice = newS; }

template < typename NoticeType>
NoticeType Subject<NoticeType>::getNotice() const { return notice; }
#endif
