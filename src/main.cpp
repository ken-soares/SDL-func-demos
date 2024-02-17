#include "SDL2/SDL.h"
#include <iostream>

#include "glad/glad.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 450

// ../build.ps1 to compile program

int main(int argv, char** args) {
	
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Error initializing video" << std::endl; 
	} else {
		std::cout << "Video system initialized successfully" << std::endl;
	}
	
	SDL_Window *window = SDL_CreateWindow("little game",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
												SDL_RENDERER_ACCELERATED);

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
		SDL_RenderPresent(renderer);
	}

	// end of program cleanup
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
