#include "Simulation.h"

void Simulation::simulate() {
   currentEvent = eventBuilder.createArrivalEvent(1);
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
   bool lineIsEmpty(line.isEmpty() );
   line.enqueue(currentEvent);
   events.dequeue();
   if(lineIsEmpty) {
      events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                       currentEvent.getDuration(),
                                                       currentEvent.getNumber()));
   }
   Event newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber()+1);
   if(newEvent.getType() != EventType::NONE) {
      events.enqueue(newEvent);
   }
}

void Simulation::processDeparture() {
   line.dequeue();
   events.dequeue();
   if(!line.isEmpty()) {
      events.enqueue(eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                       line.peekFront().getDuration(),
                                                       line.peekFront().getNumber()));
   }
}
