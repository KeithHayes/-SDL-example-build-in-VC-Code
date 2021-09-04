#include "picwindow.h"

Picwindow::Picwindow() {
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { printf( "SDL_Error: %s\n", SDL_GetError() ); }
    else { picWindow = SDL_CreateWindow( "SDL Debug Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( picWindow == NULL ) { printf( "SDL_Error: %s\n", SDL_GetError() ); }
    else { picScreenSurface = SDL_GetWindowSurface( picWindow ); }
	}
}
Picwindow::~Picwindow() {
    SDL_FreeSurface( picHelloWorld );
	picHelloWorld = NULL;
	SDL_DestroyWindow( picWindow );
	picWindow = NULL;
	SDL_Quit();
}
void Picwindow::loadpic() {
    char file[] = "../data/hello_world.bmp";
    picHelloWorld = SDL_LoadBMP( file );
	if( picHelloWorld == NULL ) {
		printf( "can't load image %s! SDL Error: %s\n", file, SDL_GetError() );
	}
}
void Picwindow::showpic() {
    SDL_BlitSurface( picHelloWorld, NULL, picScreenSurface, NULL );
	SDL_UpdateWindowSurface( picWindow );
    SDL_Delay( 5000 );
}
void Picwindow::closepic() 		{
	bool quit = false;
	SDL_Event e;
	while( !quit ) {
		while( SDL_PollEvent( &e ) != 0 ) {
			if( e.type == SDL_QUIT ) {
				quit = true;
			}
		}
		SDL_BlitSurface( picHelloWorld, NULL, picScreenSurface, NULL );
		SDL_UpdateWindowSurface( picWindow );
	}
}