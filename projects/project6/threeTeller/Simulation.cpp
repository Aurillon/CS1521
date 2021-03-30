#include "Simulation.h"

void Simulation::simulate() {
   currentEvent = eventBuilder.createArrivalEvent(0, nextLine());
   events.enqueue(currentEvent);
   while(!events.isEmpty()) {
      currentEvent = events.peekFront();
      if(currentEvent.getType() == EventType::ARRIVAL) {
         processArrival();
      }
      else {
         processDeparture();
      }
      stats.addEvent(currentEvent);
   }

   std::cout << "\nSimulation Finished.\n"<< std::endl;
   stats.reportStats();
}

void Simulation::processArrival() {
   int line = currentEvent.getLine();
   bool lineIsEmpty;
   switch(line)
   {
       case 1:
          lineIsEmpty = line1.isEmpty();
          line1.enqueue(currentEvent);
          events.dequeue();
          if(lineIsEmpty) {
             events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                              currentEvent.getDuration(),
                                                              currentEvent.getNumber(),line));
          }
          break;

       case 2:
          lineIsEmpty = line2.isEmpty();
          line2.enqueue(currentEvent);
          events.dequeue();
          if(lineIsEmpty) {
             events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                              currentEvent.getDuration(),
                                                              currentEvent.getNumber(),line));
          }
          break;

       case 3:
          lineIsEmpty = line3.isEmpty();
          line3.enqueue(currentEvent);
          events.dequeue();
          if(lineIsEmpty) {
             events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                              currentEvent.getDuration(),
                                                              currentEvent.getNumber(),line));
          }
          break;

       default:
          break;
   }
   Event newEvent;
   newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1, nextLine());
   if(newEvent.getType() != EventType::NONE) {
      events.enqueue(newEvent);
   }

}

void Simulation::processDeparture() {
   int line = currentEvent.getLine();
   switch(line)
   {
       case 1:
          line1.dequeue();
          events.dequeue();
          if(!line1.isEmpty()) {
             events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                              line1.peekFront().getDuration(),
                                                              line1.peekFront().getNumber(),
                                                              line));
          }
          break;

       case 2:
          line2.dequeue();
          events.dequeue();
          if(!line2.isEmpty()) {
             events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                              line2.peekFront().getDuration(),
                                                              line2.peekFront().getNumber(),
                                                              line));
          }
          break;

       case 3:
          line3.dequeue();
          events.dequeue();
          if(!line3.isEmpty()) {
             events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                              line3.peekFront().getDuration(),
                                                              line3.peekFront().getNumber(),
                                                              line));
          }
          break;

       default:
          break;
   }
}


int Simulation::nextLine() {
   if(line1.isEmpty()) return 1;
   else if(line2.isEmpty()) return 2;
   else if(line3.isEmpty()) return 3;
   else {
      int line = 1;
      Time L1 = line1.getLength();
      Time L2 = line2.getLength();
      Time L3 = line3.getLength();

      if(L1 < L2) {
         line = 1;
         if(L3 < L1) {
            line = 3;
         }
      }
      else if(L2 < L1)  {
         line = 2;
         if(L3 < L2) {
            line = 3;
         }
      }
      else if(L3 < L1) {
         line = 3;
      }
      else {
         return events.peekFront().getLine();
      }
      return line;
   }
}
