#include "picwindow.h"

Picwindow::Picwindow()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		mWindow = SDL_CreateWindow("SDL Debug Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								   SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (mWindow == NULL)
		{
			printf("SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			mScreenSurface = SDL_GetWindowSurface(mWindow);
		}
	}
}
Picwindow::~Picwindow()
{
	SDL_FreeSurface(mHelloWorld);
	mHelloWorld = NULL;
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	SDL_Quit();
}
void Picwindow::loadpics()
{
	char file[] = "../data/hello_world.bmp";
	mHelloWorld = SDL_LoadBMP(file);
	if (mHelloWorld == NULL)
	{
		printf("can't load image %s! SDL Error: %s\n", file, SDL_GetError());
	}
	mKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = this->loadSurface("../data/default.bmp");
	mKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = this->loadSurface("../data/up.bmp");
	mKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = this->loadSurface("../data/down.bmp");
	mKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = this->loadSurface("../data/left.bmp");
	mKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = this->loadSurface("../data/right.bmp");
}
SDL_Surface *Picwindow::loadSurface(std::string path)
{
	SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Can't load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	return loadedSurface;
}
void Picwindow::showpic()
{
	SDL_BlitSurface(mHelloWorld, NULL, mScreenSurface, NULL);
	SDL_UpdateWindowSurface(mWindow);
	//SDL_Delay( 5000 );
}
void Picwindow::events()
{
	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym) // switch on key press
				{
				case SDLK_UP:
					mCurrentSurface = mKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
					break;
				case SDLK_DOWN:
					mCurrentSurface = mKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
					break;
				case SDLK_LEFT:
					mCurrentSurface = mKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
					break;
				case SDLK_RIGHT:
					mCurrentSurface = mKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
					break;
				default:
					mCurrentSurface = mKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
					break;
				}
			}
		}
		SDL_BlitSurface(mCurrentSurface, NULL, mScreenSurface, NULL);
		SDL_UpdateWindowSurface(mWindow);
	}
}