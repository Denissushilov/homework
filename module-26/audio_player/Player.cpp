#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Player::Player()
: currentState(PlayerState::STOPPED), currentTrackIndex(-1)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Player::addTrack(const Track& track)
{
    playlist.push_back(track);
}

int Player::findTrackIndex(const std::string& title) const
{
    for(size_t i{0}; i < playlist.size(); ++i)
        if(playlist[i].getTitle() == title)
            return static_cast<int>(i);
    return -1;            
}

void Player::play()
{
    if(currentState == PlayerState::PLAYING)
        return;

    if(currentState == PlayerState::PAUSED) 
    {
        currentState = PlayerState::PLAYING;
        std::cout << "Resuming: " << playlist[currentTrackIndex].getTitle() << "\n";
        return;
    } 
    
    std::cout << "Enter track title to play: ";
    std::string title;
    std::getline(std::cin, title);
    int index = findTrackIndex(title);
    if(index != -1)
    {
        currentTrackIndex = index;
        currentState = PlayerState::PLAYING;
        std::cout << "Starting playback:\n";
        playlist[currentTrackIndex].displayInfo();
    } else {
        std::cout << "Track not found.\n";
    }
}

void Player::pause()
{
    if(currentState == PlayerState::PLAYING)
    {
        currentState = PlayerState::PAUSED;
        std::cout << "Playback paused: " << playlist[currentTrackIndex].getTitle() << "\n";
    }
}

void Player::next()
{
    if(playlist.empty())
    {
        std::cout << "Playlist is empty.\n";
        return;
    }

    currentTrackIndex = std::rand() % playlist.size();
    currentState = PlayerState::PLAYING;

    std::cout << "Shuffing to next track:\n";
    playlist[currentTrackIndex].displayInfo();
}

void Player::stop() {
    if (currentState != PlayerState::STOPPED) {
        currentState = PlayerState::STOPPED;
        std::cout << "Playback stopped.\n";
        currentTrackIndex = -1;
    }
}