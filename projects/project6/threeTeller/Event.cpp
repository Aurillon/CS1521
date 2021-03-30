#include "Event.h"

Event::Event() {
   type = EventType::ARRIVAL;
   number = 0;
   time = 0;
   duration = 0;
}

Event::Event(EventType& newType, Time& newTime, Time& newDuration,
             int& newNumber) {
   type = newType;
   number = newNumber;
   time = newTime;
   duration = newDuration;
}

Event::Event(EventType& newType, Time& currTime, int& newNumber) {
   type = newType;
   number = newNumber;
   time = currTime;
   duration = 0;
}

EventType Event::getType() const {
   return type;
}
int Event::getNumber() const {
   return number;
}
Time Event::getDuration()const {
   return duration;
}
Time Event::getTime() const {
   return time;
}
int Event::getLine() const {
   return line;
}


void Event::setEvent(const EventType newType) {
   type = newType;
}
void Event::setNumber(const int& newNumber) {
   number = newNumber;
}
void Event::setDuration(const Time& newDuration) {
   duration = newDuration;
}
void Event::setTime(const Time& newTime) {
   time = newTime;
}
void Event::setLine(const int& toLine) {
   line = toLine;
}


bool Event::operator<(const Event& rhs) const {
   return time < rhs.time;
}
bool Event::operator>=(const Event& rhs) const {
   return time >= rhs.time;
}
bool Event::operator==(const Event& rhs) const {
   return time == rhs.time;
}

bool Event::operator>(const Event& rhs) const {
   return time > rhs.time;
}
bool Event::operator<=(const Event& rhs) const {
   return time <= rhs.time;
}

bool Event::operator!=(const Event& rhs) const {
   return time != rhs.time;
}

/*
  friend bool Event::operator<(Event& lhs, Event& rhs) {
  return lhs.time < rhs.time;
  }
  friend bool Event::operator>=(Event& lhs, Event& rhs) {
  return lhs.time >= rhs.time;
  }
  friend bool Event::operator==(Event& lhs, Event& rhs) {
  return lhs.time == rhs.time;
  }
*/
