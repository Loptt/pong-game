//
// Created by charles on 2/25/18.
//

#ifndef PONG_GAME_SOUNDFILECACHE_H
#define PONG_GAME_SOUNDFILECACHE_H

#include <SFML/Audio.hpp>
#include <string>
#include <map>

class SoundFileCache
{
public:
    SoundFileCache(void);
    ~SoundFileCache(void);

    sf::Sound getSound(std::string) const;
    sf::Music* getSong(std::string) const;

private:
    static std::map<std::string, sf::SoundBuffer*> sounds;
    static std::map<std::string, sf::Music*> music;

    struct SoundFileDeallocator
    {
        void operator()(const std::pair<std::string, sf::SoundBuffer*> &p)
        {
            delete p.second;
        }
    };

    struct MusicFileDeallocator
    {
        void operator()(const std::pair<std::string, sf::Music*> &p)
        {
            delete p.second;
        }
    };

    template <typename T>
        struct Deallocator
        {
            void operator()(const std::pair<std::string,T> &p)
            {
                delete p.second;
            }
        };
};

class SoundNotFoundExeption : public std::runtime_error
{
public:
    explicit SoundNotFoundExeption(std::string const& msg) :
            std::runtime_error(msg)
    {
    }
};
#endif //PONG_GAME_SOUNDFILECACHE_H
