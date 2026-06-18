#include "Text.hpp"

#include "WaveRush/Core/Game.hpp"

Text::Text(const glm::vec2& p_Position,
		const std::string& p_FontPath,
		const std::string& p_Text,
		SDL_Color p_Color) :
		Widget(p_Position) {
	m_Text = p_Text;
	m_Color = p_Color;
	m_Font = Game::Instance().GetFontManager().GetFont(p_FontPath);

	if (m_Font) {
		m_FontSurface =
				TTF_RenderText_Blended(m_Font, m_Text.c_str(), 0, m_Color);

		m_FontTexture =
				SDL_CreateTextureFromSurface(
						Game::Instance().GetRenderer(),
						m_FontSurface);
	}

	m_LastText = m_Text;
}

void Text::ProcessRender(SDL_Renderer* p_Renderer) {
	if (!m_Font) {
		return;
	}

	if (m_Text != m_LastText) {
		SDL_DestroySurface(m_FontSurface);
		SDL_DestroyTexture(m_FontTexture);

		m_FontSurface =
				TTF_RenderText_Blended(m_Font, m_Text.c_str(), 0, m_Color);

		m_FontTexture =
				SDL_CreateTextureFromSurface(
						p_Renderer,
						m_FontSurface);

		m_LastText = m_Text;
	}

	SDL_FRect fontRect{
		m_Position.x,
		m_Position.y,
		static_cast<float>(m_FontSurface->w),
		static_cast<float>(m_FontSurface->h)
	};

	SDL_RenderTexture(
			p_Renderer,
			m_FontTexture,
			nullptr,
			&fontRect);
}