#ifndef PODIFY_H
#define PODIFY_H


#include <string>
#include "Podcast.h"
#include "Search.h"
#include "Array.h"

using namespace std;

class Podify {
  friend ostream& operator<<(ostream& os, const Podify& obj);

    public:
        void addPodcast(Podcast*);
        void addEpisode(Episode*, const string&);
        const Array<Podcast*>& getPodcasts() const;
        Podcast* getPodcast(int) const;
        Podcast* getPodcast(const string&) const;
        void getEpisodes(const Search&, Array<Episode*>&) const;

    private:
        Array<Podcast*> podcasts;
};

#endif
