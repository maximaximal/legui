#include <legui/Clickable.h>

namespace legui
{
    void Clickable::onUpdate(float frametime)
    {
        m_isButtonPressed = false;
        m_isButtonUnpressed = false;
    }
    bool Clickable::onEvent(const sf::Event &e)
    {
        if(e.type == sf::Event::MouseButtonPressed)
        {
            if(e.mouseButton.button == sf::Mouse::Left)
            {
                if(m_boundingBox.contains(e.mouseButton.x, e.mouseButton.y))
                {
                    m_isButtonPressed = true;
                    m_onPressed();
                }
            }
        }
        if(e.type == sf::Event::MouseButtonReleased)
        {
            if(e.mouseButton.button == sf::Mouse::Left)
            {
                if(m_boundingBox.contains(e.mouseButton.x, e.mouseButton.y))
                {
                    m_isButtonUnpressed = true;
                    m_onUnPressed();
                }
            }
        }
        return false;
    }
    bool Clickable::isButtonPressed()
    {
        return m_isButtonPressed;
    }
    bool Clickable::isButtonReleased()
    {
        return m_isButtonUnpressed;
    }
    Nano::signal<void()>& Clickable::onPressed()
    {
        return m_onPressed;
    }
    Nano::signal<void()>& Clickable::onUnPressed()
    {
        return m_onUnPressed;
    }
}
