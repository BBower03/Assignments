#include "Podcast.h"


Podcast::Podcast(const string& title, const string& host)
{
    this->title = title;
    this->host = host;
}

bool Podcast::equals(const string& title) const
{
    if (this->title == title) return true;
    return false;
}

Episode* Podcast::get(const int index) const
{
    return episodes[index];
}

int Podcast::getSize() const
{
    return episodes.getSize();
}

void Podcast::print(ostream& os) const
{
    os << title << "\n" << host << endl;
}

void Podcast::printWithEpisodes(ostream& os) const
{
    print(os);
    os << "\nEpisodes:\n";
    for (int i = 0; i < episodes.getSize(); ++i) {
        os << "  Episode " << i + 1 << ":\n";
        episodes[i]->print(os);
        os << '\n';
    }
}

const Array<Episode*>& Podcast::getEpisodes() const {
    return this->episodes;
}

void Podcast::add(Episode* e)
{
    episodes += e;
}

ostream& operator<<(ostream& os, const Podcast& obj)
{
    obj.printWithEpisodes(os);
    return os;
}
