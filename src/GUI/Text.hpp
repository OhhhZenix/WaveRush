#include "GUI/Widget.hpp"
#include "Math/Vec2.hpp"

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
			const Vec2f& p_Position = Vec2f(0, 0),
			const std::string& p_FontName = "JetBrainsMono.ttf",
			const std::string& p_Text = "Empty Text",
			SDL_Color p_Color = { 0, 0, 0, 255 });

	~Text() override;

	void ProcessRender(SDL_Renderer* p_Renderer) override;
};