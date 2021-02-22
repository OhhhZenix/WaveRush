#include <iostream>
#include "core/Game.hpp"

/*
- Allow adjustable speed for player (✅)
- Add particle system
- Add death system
- Add different types of enemies
- Parrying system
- Add a store
    - parrying
        - healing
        - split the enemies to double it
*/

/*
struct/class = Pascal
Function = pascal
variables = param -> p_Var, member -> m_Var, function/method var -> f_Var
*/

void main()
{
    Game::Instance().Run();
}