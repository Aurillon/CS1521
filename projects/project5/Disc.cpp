#include <iostream>
#include <string>
#include "Disc.h"

Disc::Disc() {
   title = "";
   artist = "";
   genre = "";
   year = 0;
   totalPlayTime = 0;
   multiArtist = true;
}

Disc::~Disc() {
   std::cout << title << " of type Disc Deconstrcuctor called" << std::endl;
}

bool Disc::isEmpty() const {
   return trackListPtr->isEmpty();
}

int Disc::getNumberOfTracks() const {
   return trackListPtr->getLength();
}
bool Disc::insertTrack(std::shared_ptr<Track> aTrack) {
   int amount = trackListPtr->getLength();
   return trackListPtr->insert((amount + 1), std::move(aTrack));
}

std::weak_ptr<Track> Disc::retrieveTrackByNumber(int number) const {
   std::weak_ptr<Track> wpTrack = trackListPtr->getEntry(number);
   return wpTrack;
}

std::string Disc::getArtist() const {
   return artist;
}

std::string Disc::getTitle() const {
   return title;
}

bool Disc::isMultiArtist() const {
   return multiArtist;
}

std::shared_ptr<Disc> Disc::getDiscFromUser() {
   auto newDisc = std::make_shared<Disc>();
   std::cout << "Enter Title of the Disc: ";
   getline(std::cin, newDisc->title);
   char multi;
   std::cout << "Is the Disc mutiple artists? (y or n): ";
   std::cin >> multi;
   std::cin.ignore(1000, '\n');
   if(multi == 'n') {
      newDisc->multiArtist = false;
      std::cout << "Enter Artist name: ";
      getline(std::cin, newDisc->artist);
   }
   //The year
   std::cout << "Enter the year published: ";
   std::cin >> newDisc->year;
   //the genre
   std::cout << "Enter the genre: ";
   getline(std::cin, newDisc->genre);
   //Track::getTrackFromUser
   char opt = 'y';
   while(opt == 'y') {
      auto aTrack = Track::getTrackFromUser(newDisc);
      newDisc->insertTrack(aTrack);
      newDisc->addToTotalPlayTime(aTrack->getPlayTime());
      std::cout << "Added track to the disc" << std::endl;
      std::cout << "Add another Track? (y or n): ";
      std::cin >> opt;
   }

   return newDisc;
}

void Disc::printDisc() const {
   if(!isMultiArtist()) {
      std::cout << "Disc Title: " << title
                << "\nDisc Artist: " << artist
                << "\nDisc Genre: " << genre
                << "\nDisc Year: " << year
                << "\nDisc TotalPlayTime: " << totalPlayTime/60
                << ":" << totalPlayTime - (totalPlayTime/60)*60
                << std::endl;
   }
   else {
      std::cout << "Disc Title: " << title
                << "\nDisc Genre: " << genre
                << "\nDisc Year " << year
                << "\nDisc TotalPlayTime: " << totalPlayTime/60
                << ":" << totalPlayTime - (totalPlayTime/60)*60
                << std::endl;
   }
   for(int i(1); i <= getNumberOfTracks(); ++i) {
      retrieveTrackByNumber(i).lock()->printTrack();
   }

}

void Disc::addToTotalPlayTime(int time) {
   totalPlayTime += time;
}

bool Disc::isLessThan(std::weak_ptr<Disc> discPtr) const {
   return (std::stoi(title) < std::stoi(discPtr.lock()->getTitle()));
}

bool Disc::isLessThanOrEqualTo(std::weak_ptr<Disc> discPtr) const {
   return (std::stoi(title) <= std::stoi(discPtr.lock()->getTitle()));
}
