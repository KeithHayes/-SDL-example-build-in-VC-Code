#ifndef PICWINDOW_H
#define PICWINDOW_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Picwindow
{
public:
    Picwindow();
    ~Picwindow();
    void loadpics();
    void showpic();
    void events();
    SDL_Surface* loadSurface( std::string path);


private:
    SDL_Window* mWindow;
    SDL_Surface* mScreenSurface;
    SDL_Surface* mHelloWorld;
    SDL_Surface* mKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
    SDL_Surface* mCurrentSurface;

};

#endif // PICWINDOW_H
