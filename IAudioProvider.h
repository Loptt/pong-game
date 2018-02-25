//
// Created by charles on 2/25/18.
//

#ifndef PONG_GAME_IAUDIOPROVIDER_H
#define PONG_GAME_IAUDIOPROVIDER_H

#include <string>

class IAudioProvider
{
public:
    virtual ~IAudioProvider() { }
    virtual void playSound(std::string fileName) = 0;
    virtual void playSong(std::string fileName, bool looping) = 0;
    virtual void stopAllSounds() = 0;

    virtual bool isSoundPlaying() = 0;
    virtual bool isSongPlaying() = 0;
};


#endif //PONG_GAME_IAUDIOPROVIDER_H
