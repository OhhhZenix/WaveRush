#include "GUI/Widget.hpp"
#include "Math/Vec2.hpp"

class Text : public Widget
{
    private:
        SDL_Color m_Color;

        Vec2f m_Position;

        uint32_t m_FontSize;

    public:
        explicit Text(const Vec2f& p_Position, uint32_t p_Size);

        void ProcessEvents(SDL_Event& p_Event) override;

	    void ProcessUpdate(float p_DeltaTime) override;

	    void ProcessRender(SDL_Renderer* p_Renderer) override;
};