#pragma once
#include <vector>
#include "Track.h"

enum class PlayerState {
    STOPPED,
    PLAYING,
    PAUSED
};

class Player {
private:
    std::vector<Track> playlist;
    PlayerState currentState;
    int currentTrackIndex;
    
    int findTrackIndex(const std::string& title) const;

public:
    Player();

    void addTrack(const Track& track);

    void play();
    void pause();
    void next();
    void stop();
};