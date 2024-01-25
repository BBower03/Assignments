#include "Podify.h"

void Podify::addPodcast(Podcast* podcast) {
    podcasts += podcast;
}

void Podify::addEpisode(Episode* e, const string& p) {
    Podcast* podcast = getPodcast(p);
    if (podcast) {
        podcast->add(e);
    } else {
        cerr << "Error: podcast not found " << p;
        exit(1);
    }
}

const Array<Podcast*>& Podify::getPodcasts() const {
    return podcasts;
}

Podcast* Podify::getPodcast(int index) const {
    if (index < 0 || index >= podcasts.getSize()) {
        cerr << "Error: Podcast array out of bounds" << endl;
        exit(1);
    }
    return podcasts[index];
}

Podcast* Podify::getPodcast(const string& title) const {
    for (int i = 0; i < podcasts.getSize(); i++) {
        if (podcasts[i]->equals(title)) {
            return podcasts[i];
        }
    }
    cerr << "Error: podcast not found: " << title << endl;
    exit(1);
}

void Podify::getEpisodes(const Search& s, Array<Episode*>& e) const {
    for (int i = 0; i < podcasts.getSize(); i++) {
        const Array<Episode*>& episodes = podcasts[i]->getEpisodes();
        for (int j = 0; j < episodes.getSize(); j++) {
            if (s.matches(episodes[j])) {
                e += episodes[j];
            }
        }
    }
}

ostream& operator<<(ostream& os, const Podify& obj)
{
    for (int i = 0; i < obj.getPodcasts().getSize(); i++) {
      os << obj.getPodcast(i);
    }
    return os;
}
