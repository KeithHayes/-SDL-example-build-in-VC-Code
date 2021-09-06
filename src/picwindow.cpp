#include "picwindow.h"

Picwindow::Picwindow() {
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
Picwindow::~Picwindow() {
	SDL_FreeSurface(mKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT]);
	SDL_FreeSurface(mKeyPressSurfaces[KEY_PRESS_SURFACE_UP]);
	SDL_FreeSurface(mKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN]);
	SDL_FreeSurface(mKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT]);
	SDL_FreeSurface(mKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT]);
	SDL_FreeSurface(mLoadedSurface);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}
void Picwindow::loadpics() {
	mKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = this->loadSurface("../data/default.bmp");
	mKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = this->loadSurface("../data/up.bmp");
	mKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = this->loadSurface("../data/down.bmp");
	mKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = this->loadSurface("../data/left.bmp");
	mKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = this->loadSurface("../data/right.bmp");
}
SDL_Surface *Picwindow::loadSurface(std::string path) {
	SDL_Surface* systemSurface;
	SDL_Surface* opaqueSurface = SDL_LoadBMP(path.c_str());
	if (opaqueSurface == NULL) { printf("Can't load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError()); }
	else {  // format to screen
		systemSurface = SDL_ConvertSurface(opaqueSurface, mScreenSurface->format, 0);
		SDL_FreeSurface(opaqueSurface);
	}
	return systemSurface;
}
void Picwindow::showpic() {
	SDL_BlitSurface(mKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT], NULL, mScreenSurface, NULL);
	SDL_UpdateWindowSurface(mWindow);
}
SDL_Surface* Picwindow::clippic() {
	SDL_Surface* largesurface = this->loadSurface("../data/forest1280.bmp");
	mLoadedSurface = this->loadSurface("../data/default.bmp");
	SDL_Rect stretchRect;
	stretchRect.x = 320;
	stretchRect.y = 240;
	stretchRect.w = SCREEN_WIDTH;
	stretchRect.h = SCREEN_HEIGHT;
	SDL_BlitScaled(largesurface, &stretchRect, mLoadedSurface, NULL);
	//SDL_BlitScaled( largesurface, NULL, mLoadedSurface, NULL);
	SDL_FreeSurface(largesurface);
	return mLoadedSurface;
}
SDL_Surface* Picwindow::zoompic() {
	SDL_Surface* smallSurface = this->loadSurface("../data/forest320.bmp");
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = SCREEN_WIDTH;
	stretchRect.h = SCREEN_HEIGHT;
	SDL_BlitScaled(smallSurface, NULL, mLoadedSurface, &stretchRect);
	SDL_FreeSurface(smallSurface);
	return mLoadedSurface;
}

void Picwindow::events() {
	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
				case SDL_QUIT:
					quit = true;
				break;
				case SDL_KEYDOWN:
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
					case SDLK_HOME:
						mCurrentSurface = mKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
					break;
					case SDLK_PAGEUP:
						mCurrentSurface = zoompic();
					break;
					case SDLK_PAGEDOWN:
						mCurrentSurface = clippic();
					break;				
					default:largesurface
					break;
				}
				break;
				case SDL_KEYUP:
				break;
			}
		}
		SDL_BlitSurface(mCurrentSurface, NULL, mScreenSurface, NULL);
		SDL_UpdateWindowSurface(mWindow);
	}
}