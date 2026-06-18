#pragma once

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <unordered_map>

class FontManager {
private:
	std::unordered_map<std::string, TTF_Font*> m_FontList;

public:
	~FontManager();

	void LoadFont(const char* p_FontPath);

	TTF_Font* GetFont(const std::string& p_FontPath);
};