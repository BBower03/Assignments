#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include <string>
#include <iostream>
#include <fstream>
#include "Episode.h"

using namespace std;

class PodcastPlayer {
    public:
        virtual void play(const Episode&, ostream&) const = 0;

};

class AudioPlayer : public PodcastPlayer {
    public:
        void play(const Episode&, ostream&) const override;
};

class VideoPlayer : public AudioPlayer {
    public:
        void play(const Episode&, ostream&) const override;
};



#endif
