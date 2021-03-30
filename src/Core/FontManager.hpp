#pragma once

#include "Core/PCH.hpp"

constexpr uint32_t c_BaseSize = 200;

struct FontData {
	TTF_Font *Font;
	int width;
	int height;
};

class FontManager {
private:
	std::unordered_map<std::string, FontData*> m_FontList;

public:
	~FontManager();

	void LoadFont(const char* p_FontPath);

	FontData *GetFont(const std::string& p_FontPath);
};