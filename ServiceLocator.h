//
// Created by charles on 2/25/18.
//

#ifndef PONG_GAME_SERVICELOCATOR_H
#define PONG_GAME_SERVICELOCATOR_H

#include "IAudioProvider.h"

class ServiceLocator
{
public:
    static IAudioProvider* getAudio()
    {
        return audioProvider;
    }

    static void registerServiceLocator(IAudioProvider* provider)
    {
        audioProvider = provider;
    }

private:
    static IAudioProvider *audioProvider;
};


#endif //PONG_GAME_SERVICELOCATOR_H
