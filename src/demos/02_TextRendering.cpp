#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "glad/glad.h"


#include <iostream>


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 450

// ../build.ps1 to compile program

void loadSystems() {
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Error initializing video" << std::endl; 
	} else {
		std::cout << "Video system initialized successfully" << std::endl;
	}
	
	if(TTF_Init() == -1) {
		std::cout << "Could not initialize SDL2 ttf, error: " << TTF_GetError() << std::endl;
	}else {
		std::cout << "SDL2 ttf initialized successfully" << std::endl;
	}
}

int main(int argv, char** args) {
	
	loadSystems();
		
	SDL_Window *window = SDL_CreateWindow("little game",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
												SDL_RENDERER_ACCELERATED);

	TTF_Font *font = TTF_OpenFont("./res/endor/ENDOR.ttf", 28);
	
	if(font == nullptr) {
		std::cout << "could not load font" << std::endl;
		exit(1);
	}
	
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, "A game about elves",
													{255,255,255});
													
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_FreeSurface(textSurface);
	
	SDL_Rect textRect;
	
	textRect.w = 300;
	textRect.h = 75;
	textRect.x = (int)(WINDOW_WIDTH / 2 - textRect.w/2);
	textRect.y = 10;

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
		
		SDL_RenderCopy(renderer, texture, NULL, &textRect);
		SDL_RenderPresent(renderer);
	}

	// end of program cleanup
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
