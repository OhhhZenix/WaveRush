#include "Text.hpp"
#include "Core/Game.hpp"

Text::Text(const Vec2f& p_Position, const std::string& p_FontName, const std::string& p_Text, SDL_Color p_Color)
: Widget(), m_Text(p_Text), m_Color(p_Color)
{
    m_Position = p_Position;
    
    m_Font = Game::Instance().GetFontManager().GetFont("Alphakind.ttf");

    m_FontSurface = TTF_RenderText_Blended(m_Font, m_Text.c_str(), m_Color);
    m_FontTexture = SDL_CreateTextureFromSurface(NULL, m_FontSurface);
}

void Text::ProcessRender(SDL_Renderer* p_Renderer)
{
    if (m_Font == nullptr)
        return;

    if (m_Text != m_LastText) 
    {
        SDL_FreeSurface(m_FontSurface);
        SDL_DestroyTexture(m_FontTexture);

        m_FontSurface = TTF_RenderText_Blended(m_Font, m_Text.c_str(), m_Color);
        m_FontTexture = SDL_CreateTextureFromSurface(p_Renderer, m_FontSurface);
        
        m_LastText = m_Text;
    }

    static SDL_Rect f_FontRect = {
        (int)m_Position.X,
        (int)m_Position.Y,
        m_FontSurface->w,
        m_FontSurface->h
    };

    SDL_RenderCopy(p_Renderer, m_FontTexture, NULL, &f_FontRect);

}