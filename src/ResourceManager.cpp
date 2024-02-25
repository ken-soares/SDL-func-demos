#include "ResourceManager.hpp"

ResourceManager::ResourceManager() {
	
}

ResourceManager::ResourceManager(ResourceManager const&) {
	
}

ResourceManager ResourceManager::operator=(ResourceManager const&) {
	
	// TODO: Although we do not need this for a singleton
	return *this;
}

// Instantiate exactly one instance of our class (Singleton)
ResourceManager& ResourceManager::GetInstance() {
	static ResourceManager* s_instance = new ResourceManager;
	
	return *s_instance;
}

SDL_Surface* ResourceManager::GetSurface(std::string filepath) {
	// We will look through m_surfaces unordered_map and see if a file exists
	
	// if the file does exist, return the associated surface
	
	
	auto search = m_surfaces.find(filepath);
	
	if(search != m_surfaces.end()) {
		return m_surfaces[filepath];
	} else {		
	
		std::cout << "Image allocated once\n";
		SDL_Surface *surface = IMG_Load(filepath.c_str());
		m_surfaces.insert(std::make_pair(filepath, surface));
		return m_surfaces[filepath];
	}
	
	// failing case
	return nullptr;
}