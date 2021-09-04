#ifndef PICWINDOW_H
#define PICWINDOW_H

#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Picwindow
{
public:
    Picwindow();
    ~Picwindow();
    void loadpic();
    void showpic();
    void closepic();

private:
    SDL_Window* picWindow;
    SDL_Surface* picScreenSurface;
    SDL_Surface* picHelloWorld;
};

#endif // PICWINDOW_H
