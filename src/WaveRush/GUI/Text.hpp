#include "WaveRush/GUI/Widget.hpp"

#include <SDL3/SDL_ttf.h>
#include <string>

class Text : public Widget {
private:
	std::string m_Text;
	std::string m_LastText;
	SDL_Color m_Color;
	TTF_Font* m_Font;
	SDL_Texture* m_FontTexture;
	SDL_Surface* m_FontSurface;

public:
	explicit Text(
			const glm::vec2& p_Position = glm::vec2(0, 0),
			const std::string& p_FontPath = "assets/fonts/JetBrainsMono.ttf",
			const std::string& p_Text = "Empty Text",
			SDL_Color p_Color = { 0, 0, 0, 255 });

	void ProcessRender(SDL_Renderer* p_Renderer) override;
};