#include "Text.hpp"
#include "Core/Game.hpp"

Text::Text(const Vec2<float>& p_Position, const std::string& p_FontPath, float p_FontSize, const std::string& p_Text, SDL_Color p_Color) :
		Widget(p_Position) {
	m_Text = p_Text;
	m_Color = p_Color;
	m_FontSize = p_FontSize;
	m_FontData = Game::Instance().GetFontManager().GetFont(p_FontPath);
	m_FontSurface = TTF_RenderText_Blended(m_FontData->Font, m_Text.c_str(), m_Color);
	m_FontTexture = SDL_CreateTextureFromSurface(Game::Instance().GetRenderer(), m_FontSurface);

	SDL_SetTextureBlendMode(m_FontTexture, SDL_BLENDMODE_MUL);
}


void Text::ProcessRender(SDL_Renderer* p_Renderer) {
	if (m_FontData == nullptr) {
		return;
	}

	SDL_Rect f_FontRect = {
		static_cast<int>(m_Position.X),
		static_cast<int>(m_Position.Y),
		((m_FontData->width * m_FontSize) / (int)c_BaseSize) * (int)m_Text.length(),
		(m_FontData->height * m_FontSize) / (int)c_BaseSize
	};

	SDL_Rect f_SrcFontRect = {
		0,
		0,
		m_FontSurface->w,
		m_FontSurface->h
	};

	SDL_RenderCopy(p_Renderer, m_FontTexture, &f_SrcFontRect, &f_FontRect);
}

void Text::ProcessUpdate(float p_DeltaTime) {
	m_FontSize += 3 * p_DeltaTime;
}