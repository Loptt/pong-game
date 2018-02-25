cmake_minimum_required(VERSION 3.9)
project(pong-game)

set(CMAKE_CXX_STANDARD 11)

add_executable(pong-game main.cpp main.cpp Game.cpp Game.h SplashScreen.cpp SplashScreen.h MainMenu.cpp MainMenu.h Button.h Button.cpp VisibleGameObject.cpp VisibleGameObject.h PlayerPaddle.cpp PlayerPaddle.h GameObjectManager.cpp GameObjectManager.h GameBall.cpp GameBall.h IAudioProvider.cpp IAudioProvider.h SFMLSoundProvider.cpp SFMLSoundProvider.h ServiceLocator.cpp ServiceLocator.h SoundFileCache.cpp SoundFileCache.h)

configure_file(images/Splashscreen.png images/Splashscreen.png COPYONLY)
configure_file(images/Mainmenu.png images/Mainmenu.png COPYONLY)
configure_file(images/paddle.png images/paddle.png COPYONLY)
configure_file(images/ball.png images/ball.png COPYONLY)
configure_file(audio/kaboom.wav audio/kaboom.wav COPYONLY)
configure_file(audio/Soundtrack.ogg audio/Soundtrack.ogg COPYONLY)
configure_file(audio/bounce.wav audio/bounce.wav COPYONLY)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(pong-game ${SFML_LIBRARIES})
endif()