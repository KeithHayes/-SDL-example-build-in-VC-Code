#include <SDL2/SDL.h>
#include <stdio.h>
#include "picwindow.h"

int main( int argc, char* args[] )
{
	Picwindow mywin;
	mywin.loadpic();
	mywin.showpic();
	mywin.closepic();
	return 0;
}
