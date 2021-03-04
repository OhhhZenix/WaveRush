#include "GUI/Widget.hpp"
#include "Math/Vec2.hpp"

class Button : public Widget {
private:
	SDL_Color m_Color;
	Vec2f m_Position;
	Vec2f m_Size;

public:
	explicit Button(const Vec2f& p_Position, const Vec2f& p_Size);

	void ProcessEvents(SDL_Event& p_Event) override;

	void ProcessUpdate(float p_DeltaTime) override;

	void ProcessRender(SDL_Renderer* p_Renderer) override;
};