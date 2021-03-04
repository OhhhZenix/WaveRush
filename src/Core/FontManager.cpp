#include "FontManager.hpp"

FontManager::~FontManager() {
	if (!m_FontList.empty()) {
		for (auto& [f_Key, f_Value] : m_FontList) {
			if (f_Value != nullptr) {
				continue;
			}
			TTF_CloseFont(f_Value);
		}
		m_FontList.clear();
	}
}

void FontManager::LoadFont(const char* p_FontPath) {
	// Open font
	TTF_Font* f_Font = TTF_OpenFont(p_FontPath, 64);
	if (f_Font == nullptr) {
		std::cout << "[Font] \"" << p_FontPath << "\" not found.\n";
		return;
	}

	// Save font
	std::cout << p_FontPath << " found.\n";
	m_FontList.emplace(p_FontPath, f_Font);
}

TTF_Font* FontManager::GetFont(const std::string& p_FontPath) {
	TTF_Font* f_Font = m_FontList.at(p_FontPath);
	if (f_Font) {
		std::cout << "[Font] \"" << p_FontPath << "\" found.";
		return f_Font;
	}

	std::cout << "[Font] \"" << p_FontPath << "\" is not stored.";
	return nullptr;
}