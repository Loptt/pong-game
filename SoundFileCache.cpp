//
// Created by charles on 2/25/18.
//

#include "SoundFileCache.h"

SoundFileCache::SoundFileCache(void)
{

}

SoundFileCache::~SoundFileCache(void)
{
    std::for_each(sounds.begin(),sounds.end(), Deallocator<sf::SoundBuffer*>());
    std::for_each(music.begin(),music.end(), Deallocator<sf::Music*>());
}

sf::Sound SoundFileCache::getSound(std::string soundName) const
{
    std::map<std::string, sf::SoundBuffer*>::iterator itr = sounds.find(soundName);

    if(itr == sounds.end())
    {
        sf::SoundBuffer *soundBuffer = new sf::SoundBuffer();
        if(!soundBuffer->loadFromFile(soundName))
        {
            delete soundBuffer;
            throw SoundNotFoundExeption(soundName + "was not found");
        }

        std::map<std::string, sf::SoundBuffer *>::iterator res =
                sounds.insert(std::pair<std::string,sf::SoundBuffer*>(soundName,soundBuffer)).first;

        sf::Sound sound;
        sound.setBuffer(*soundBuffer);
        return sound;
    }
    else
    {
        sf::Sound sound;
        sound.setBuffer(*itr->second);
        return sound;
    }
}

sf::Music *SoundFileCache::getSong(std::string soundName) const
{
    std::map<std::string, sf::Music*>::iterator itr = music.find(soundName);

    if(itr == music.end())
    {
        sf::Music *song = new sf::Music();
        if(!song->openFromFile(soundName))
        {
            delete song;
            throw SoundNotFoundExeption(soundName + "was not found");
        }

        std::map<std::string, sf::Music *>::iterator res =
                music.insert(std::pair<std::string,sf::Music*>(soundName,song)).first;

        return res->second;
    }
    else
    {
        return itr->second;
    }
}

std::map<std::string, sf::SoundBuffer*> SoundFileCache::sounds;
std::map<std::string, sf::Music*> SoundFileCache::music;
