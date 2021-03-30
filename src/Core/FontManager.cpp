#include "FontManager.hpp"

FontManager::~FontManager() {
	if (!m_FontList.empty()) {
		for (auto& [f_Key, f_Value] : m_FontList) {
			if (f_Value == nullptr) {
				continue;
			}
			TTF_CloseFont(f_Value->Font);
			delete f_Value;
		}
		m_FontList.clear();
	}
}

void FontManager::LoadFont(const char* p_FontPath) {
	// Open font
	FontData *f_FontData = new FontData;
	f_FontData->Font = TTF_OpenFont(p_FontPath, c_BaseSize);

	if (f_FontData->Font == nullptr) {
		std::cout << "[Font] \"" << p_FontPath << "\" not found.\n";
		return;
	}

	SDL_Surface *f_ExampleSurface = TTF_RenderText_Solid(f_FontData->Font, "A", {0, 0, 0, 0});
	
	f_FontData->width = f_ExampleSurface->w;
	f_FontData->height = f_ExampleSurface->h;

	SDL_FreeSurface(f_ExampleSurface);

	// Save font
	std::cout << p_FontPath << " found.\n";
	m_FontList.emplace(p_FontPath, f_FontData);
}

FontData *FontManager::GetFont(const std::string& p_FontPath) {
	FontData *f_FontData = m_FontList.at(p_FontPath);
	if (f_FontData) {
		std::cout << "[Font] \"" << p_FontPath << "\" found.";
		return f_FontData;
	}

	std::cout << "[Font] \"" << p_FontPath << "\" is not stored.";
	return nullptr;
}