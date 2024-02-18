#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>
#include <string>

class TextureRect {
	public:
	
		// TextureRect constructor
		TextureRect(SDL_Renderer *renderer, std::string filepath);
		// TextureRect destructor
		~TextureRect();
		void SetProperties(int x, int y, int w, int h);		
		// Update every frame
		void Update();
		// rendering
		void Render(SDL_Renderer *renderer);
		
	private:
		SDL_Rect m_rect;
		SDL_Texture *m_texture; 
};