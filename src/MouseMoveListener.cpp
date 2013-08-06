#include <legui/MouseMoveListener.h>

namespace legui
{
    MouseMoveListener::MouseMoveListener(Container *parent)
        : Widget(parent)
    {
        
    }
    void MouseMoveListener::onUpdate(float frametime)
    {
    
    }
    bool MouseMoveListener::onEvent(const sf::Event &e)
    {
        if(e.type == sf::Event::MouseMoved)
        {
            sf::Vector2f newPos;
            newPos.x = m_oldMousePos.x - e.mouseMove.x;
            newPos.y = m_oldMousePos.y - e.mouseMove.y;
            m_oldMousePos = newPos;
            mouseMoved(newPos);
        }
        return false;
    }
    void MouseMoveListener::mouseMoved(sf::Vector2f delta)
    {
    
    }
}
