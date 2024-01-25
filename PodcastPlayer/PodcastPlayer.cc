#include "PodcastPlayer.h"

void AudioPlayer::play(const Episode& e, ostream& os) const {
    os << "Playing audio: " << e.getAudio() << endl;
}

void VideoPlayer::play(const Episode& e, ostream& os) const {
    AudioPlayer::play(e, os);

    ifstream videoFile(e.getVideoFile());
    if (videoFile.is_open()) {
        os << "Playing video: " << e.getVideoFile() << endl;
        string line;
        while (getline(videoFile, line)) {
            os << line << endl;
        }
        videoFile.close();
    } else {
        os << "Cannot open file: " << e.getVideoFile() << endl;
        exit(1);
    }
}
