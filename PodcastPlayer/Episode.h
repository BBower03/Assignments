#ifndef EPISODE_H
#define EPISODE_H

#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Episode {

    friend ostream& operator<<(ostream& os, const Episode& obj);

    public:
        Episode(const string&, const string&, const string&, const string&, const string&, const string&);
        const string& getPodcastTitle() const;
        const string& getHost() const;
        const string& getEpisodeTitle() const;
        const string& getCategory() const;
        const string& getAudio() const;
        const string& getVideoFile() const;
        void print(ostream&) const;

    private:
        string podcastTitle;
        string host;
        string episodeTitle;
        string category;
        string audio;
        string videoFile;

};

#endif
