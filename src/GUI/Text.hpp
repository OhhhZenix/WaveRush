#include "GUI/Widget.hpp"
#include "Math/Vec2.hpp"

class Text : public Widget
{
    private:
        std::string m_Text = "Empty Text";

        std::string m_LastText = "Empty Text";

        SDL_Color m_Color = {255, 255, 255, 255};

        TTF_Font *m_Font = nullptr;

        SDL_Texture *m_FontTexture = nullptr;

        SDL_Surface *m_FontSurface = nullptr;

    public:
        explicit Text(const Vec2f& p_Position = Vec2f(0, 0), const std::string& p_FontName = "JetBrainsMono.ttf", const std::string& p_Text = "Empty", SDL_Color p_Color = {0, 0, 0, 255});

        void ProcessEvents(SDL_Event& p_Event) override {};

	    void ProcessUpdate(float p_DeltaTime) override {};

	    void ProcessRender(SDL_Renderer* p_Renderer) override;
};