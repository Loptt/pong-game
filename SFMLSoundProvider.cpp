//
// Created by charles on 2/25/18.
//

#include "SFMLSoundProvider.h"


SFMLSoundProvider::SFMLSoundProvider() :
currentSongName("")
{

}

void SFMLSoundProvider::playSound(std::string fileName)
{
    int availChannel = -1;

    for (int i = 0; i < MAX_SOUND_CHANNELS; ++i)
    {
        if (currentSounds[i].getStatus() != sf::Sound::Playing)
        {
            availChannel = i;
        }
    }

    if (availChannel != -1)
    {
        try
        {
            currentSounds[availChannel] = soundFileCache.getSound(fileName);
            currentSounds[availChannel].play();
        }
        catch(SoundNotFoundExeption &snfe)
        {

        }

    }
}

void SFMLSoundProvider::playSong(std::string fileName, bool isLooping)
{
    sf::Music *currentSong;

    try
    {
        currentSong = soundFileCache.getSong(fileName);
    }
    catch (SoundNotFoundExeption&)
    {
        return;
    }

    if (!currentSongName.empty())
    {
        try
        {
            sf::Music *priorSong = soundFileCache.getSong(currentSongName);

            if (priorSong->getStatus() != sf::Sound::Stopped)
            {
                priorSong->stop();
            }
        }
        catch(SoundNotFoundExeption&)
        {

        }

    }

    currentSongName = fileName;
    currentSong->setLoop(isLooping);
    currentSong->play();

}

void SFMLSoundProvider::stopAllSounds()
{
    for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
    {
        currentSounds[i].stop();
    }

    if(!currentSongName.empty())
    {
        sf::Music *currentSong = soundFileCache.getSong(currentSongName);
        if (currentSong->getStatus() == sf::Sound::Playing)
        {
            currentSong->stop();
        }
    }
}

bool SFMLSoundProvider::isSoundPlaying()
{
    for (int i; i < MAX_SOUND_CHANNELS; ++i)
    {
        if (currentSounds[i].getStatus() == sf::Sound::Playing)
        {
            return true;
        }
    }

    return false;
}

bool SFMLSoundProvider::isSongPlaying()
{
    if (!currentSongName.empty())
    {
        return soundFileCache.getSong(currentSongName)->getStatus() == sf::Music::Playing;
    }

    return false;
}
