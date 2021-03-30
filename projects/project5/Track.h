#ifndef TRACK_
#define TRACK_

#include <memory>
#include <string>
#include "Disc.h"

class Track {
  public:
   Track() = delete;
   Track(std::shared_ptr<Disc>);
   ~Track();
   void printTrack() const;
   bool isLessThan(std::weak_ptr<Track> aTrack) const;
   int getNumber() const;
   int getPlayTime() const;
   int readPlayTime();
   static std::shared_ptr<Track> getTrackFromUser(std::shared_ptr<Disc> aDisc);

  private:
   std::string name;
   std::string artist;
   int playTime;
   int number;
   std::string location;
   std::weak_ptr<Disc> discPtr;
};

#endif
