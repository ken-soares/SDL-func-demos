#include "TextureRect.hpp"
#include "ResourceManager.hpp"

TextureRect::TextureRect(SDL_Renderer *renderer, std::string filepath) {
	SDL_Surface *retrieveSurface = ResourceManager::GetInstance().GetSurface("res/f_spritesheet.png");
	m_texture = SDL_CreateTextureFromSurface(renderer, retrieveSurface);
}

TextureRect::~TextureRect() {
	SDL_DestroyTexture(m_texture);
}

void TextureRect::SetProperties(int x, int y, int w, int h) {
	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;
}

// copy constructor
// copy assignment operator


// Update every frame
void TextureRect::Update() {
	
}

// rendering
void TextureRect::Render(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, m_texture, NULL, &m_rect);				
}