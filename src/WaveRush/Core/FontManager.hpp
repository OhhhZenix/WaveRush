#pragma once

#include <SDL_ttf.h>
#include <unordered_map>

class FontManager {
private:
	std::unordered_map<std::string, TTF_Font*> m_FontList;

public:
	~FontManager();

	void LoadFont(const char* p_FontPath);

	TTF_Font* GetFont(const std::string& p_FontPath);
};