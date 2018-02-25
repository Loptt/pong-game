//
// Created by charles on 2/25/18.
//

#ifndef PONG_GAME_SFMLSOUNDPROVIDER_H
#define PONG_GAME_SFMLSOUNDPROVIDER_H

#include <SFML/Audio.hpp>
#include "IAudioProvider.h"
#include "SoundFileCache.h"

class SFMLSoundProvider : public IAudioProvider
{
public:

    SFMLSoundProvider();

    void playSound(std::string fileName) override;
    void playSong(std::string fileName, bool isLooping) override;
    void stopAllSounds() override;

    bool isSoundPlaying() override;
    bool isSongPlaying() override;

private:
    static const int MAX_SOUND_CHANNELS = 5;

    SoundFileCache soundFileCache;
    sf::Sound currentSounds[MAX_SOUND_CHANNELS];
    std::string currentSongName;
};


#endif //PONG_GAME_SFMLSOUNDPROVIDER_H
