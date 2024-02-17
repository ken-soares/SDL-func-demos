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
												
	

	/*
	* Loading the Demon Axe Texture for display
	* NB: surface: pixels, texture: image data on the GPU
	*/
	
	SDL_Surface *surface = SDL_LoadBMP("res/demon_axe.bmp");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	
	// demon axe texture rectangle
	SDL_Rect rectangle;
    rectangle.w = 50;
	rectangle.h = 50;
	rectangle.x = 5;
	rectangle.y = 100;
	
	// inventory background rectangle
	SDL_Rect background;
	background.w = rectangle.w;
	background.h = 4 * rectangle.h;
	background.x = rectangle.x;
	background.y = rectangle.y;

	bool gameRunning = true;
	
	// demon axe is picked or not
	bool slotOnePicked = false;
	
	/* MAIN LOOP */
	while(gameRunning) {
		SDL_Event event;
		
		while(SDL_PollEvent(&event)) {
			// handle close events	
			if(event.type == SDL_QUIT) {
				gameRunning = false;
			}
			
			// demon axe follows mouse cursor if selected
			if(event.type == SDL_MOUSEMOTION && slotOnePicked) {
				rectangle.x = event.motion.x - (int)(rectangle.w / 2);
				rectangle.y = event.motion.y - (int)(rectangle.h / 2);
			}
			
			
			if (event.type == SDL_KEYDOWN) {
				switch(event.key.keysym.scancode){
					
					// demon axe key is 1
					case SDL_SCANCODE_1:
						slotOnePicked = true;
						break;
					
					// reset key is escape
					case SDL_SCANCODE_ESCAPE:
						slotOnePicked = false;
						rectangle.x = 5;
						rectangle.y = 100;
						break;
						
					default:
						break;
				}
			}
			
			// demon axe click transparency effect
			if (event.type == SDL_MOUSEBUTTONDOWN && 
				event.button.button == SDL_BUTTON_LEFT) {
				SDL_SetTextureAlphaMod(texture, 150);
			}else {
				SDL_SetTextureAlphaMod(texture, 255);
			}
		}	
	
		SDL_SetRenderDrawColor(renderer, 0,0,255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0,0,0, 82);
		SDL_RenderDrawRect(renderer, &background);
		
		// sending demon axe texture to renderer
		SDL_RenderCopy(renderer, texture, NULL, &rectangle);
		
		SDL_RenderPresent(renderer);
	}

	// end of program cleanup
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
