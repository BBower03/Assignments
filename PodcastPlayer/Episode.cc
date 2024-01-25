#include "Episode.h"


Episode::Episode(const string& getPodcastTitle, const string& host, const string& episodeTitle, const string& category, const string& audio, const string& videoFile)
{
    this->podcastTitle = podcastTitle;
    this->host = host;
    this->episodeTitle = episodeTitle;
    this->category = category;
    this->audio = audio;
    this->videoFile = videoFile;
}

const string& Episode::getPodcastTitle() const
{
    return podcastTitle;
}

const string& Episode::getHost() const
{
    return host;
}

const string& Episode::getEpisodeTitle() const
{
    return episodeTitle;
}

const string& Episode::getCategory() const
{
    return category;
}

const string& Episode::getAudio() const
{
    return audio;
}

const string& Episode::getVideoFile() const
{
    return videoFile;
}

void Episode::print(ostream& os) const
{
    os << podcastTitle << "\n"
        << host << "\n" << category << "\n"
        << episodeTitle;

}

ostream& operator<<(ostream& os, const Episode& obj)
{
    obj.print(os);
    return os;
}
