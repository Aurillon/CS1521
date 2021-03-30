#ifndef EVENT_
#define EVENT_

#include "Time.h"
#include "EventType.h"

class Event {
  public:
   Event();
   Event(EventType&, Time&, Time&, int&);
   Event(EventType&, Time&, int&);
   ~Event() = default;

   //Getters
   EventType getType() const;
   Time getTime() const;
   Time getDuration() const;
   int getNumber() const;

   //Setters
   void setEvent(const EventType);
   void setTime(const Time&);
   void setDuration(const Time&);
   void setNumber(const int&);

   //Operators
   bool operator<(const Event&) const;
   bool operator>=(const Event&) const;
   bool operator==(const Event&) const;
   bool operator>(const Event&) const;
   bool operator<=(const Event&) const;
   bool operator!=(const Event&) const;

   /*
   friend bool operator==(Event&, Event&);
   friend bool operator>=(Event&, Event&);
   friend bool operator<(Event&, Event&);
   */
   
  private:
   EventType type;
   Time time;
   Time duration;
   int number;
};

#endif
