#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureRect.hpp"

#include <iostream>
#include <string>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 450

// ../build.ps1 to compile program

void loadSystems() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Error initializing video" << std::endl; 
	}else {
		std::cout << "Video system initialized successfully" << std::endl;
	}
	
	
	// SDL2_Image setup from wiki page
	int imgFlags = IMG_INIT_PNG;
	int initStatus = IMG_Init(imgFlags);
	
	if(imgFlags & initStatus != imgFlags) {
		std::cout << "SDL2_Image format not available" << std::endl;
	}else {
		std::cout << "SDL2_Image format initialized successfully" << std::endl;
	}
}




int main(int argv, char** args) {
	
	loadSystems();
		
	SDL_Window *window = SDL_CreateWindow("little game",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
												SDL_RENDERER_ACCELERATED);
	
	
	TextureRect spritesheet(renderer, "./res/f_spritesheet.png");
	spritesheet.SetProperties(100,100,256,256);
	
	bool gameRunning = true;
	
	/* MAIN LOOP */
	while(gameRunning) {
		SDL_Event event;
		
		while(SDL_PollEvent(&event)) {
			// handle close events	
			if(event.type == SDL_QUIT) {
				gameRunning = false;
			}
		}	
	
		SDL_SetRenderDrawColor(renderer, 0,0,255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		spritesheet.Render(renderer);
		
		SDL_RenderPresent(renderer);
	}

	// end of program cleanup
	SDL_DestroyWindow(window);
	
	IMG_Quit();
	SDL_Quit();
	return 0;
}
