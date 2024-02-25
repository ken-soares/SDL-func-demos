#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ResourceManager {
	private:
		ResourceManager();
		
		// avoid making copies of the resource manager
		ResourceManager(ResourceManager const&);
		
		// avoid copy assignment operator
		ResourceManager operator=(ResourceManager const&);
		
		std::unordered_map<std::string, SDL_Surface*> m_surfaces;
		
	public:
		static ResourceManager& GetInstance();
		SDL_Surface *GetSurface(std::string filepath);
};