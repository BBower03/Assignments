#ifndef PODCAST_H
#define PODCAST_H

#include <string>
#include "Episode.h"
#include "Array.h"

using namespace std;


class Podcast {

    friend ostream& operator<<(ostream& os, const Podcast& obj);

    public:
        Podcast(const string&, const string&);
        bool equals(const string&) const;
        Episode* get(const int) const;
        int getSize() const;
        void print(ostream&) const;
        void printWithEpisodes(ostream&) const;
        void add(Episode*);
        const Array<Episode*>& getEpisodes() const;

    private:
        Array<Episode*> episodes;
        string title, host;
};

#endif
