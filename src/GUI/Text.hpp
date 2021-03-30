#pragma once

#include "GUI/Widget.hpp"
#include "Math/Vec2.hpp"
#include "Core/FontManager.hpp"

class Text : public Widget {
private:
	std::string m_Text;
	std::string m_LastText;
	FontData* m_FontData;
	SDL_Color m_Color;
	float m_FontSize;
	SDL_Texture *m_FontTexture;
	SDL_Surface *m_FontSurface;

	SDL_Rect m_FullRect;

public:
	explicit Text(
			const Vec2<float>& p_Position = Vec2<float>(0, 0),
			const std::string& p_FontPath = "assets/fonts/JetBrainsMono.ttf",
			float p_FontSize = 10,
			const std::string& p_Text = "Empty Text",
			SDL_Color p_Color = { 0, 0, 0, 255 });

	void ProcessRender(SDL_Renderer* p_Renderer) override;

	virtual void ProcessUpdate(float p_DeltaTime) override;
};