#include <legui/Clickable.h>

namespace legui
{
    Clickable::Clickable(Container *parent)
        : Focusable(parent)
    {
        m_isButtonPressed = false;
        m_isButtonUnpressed = false;
        m_pressed = false;
    }
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
                    m_pressed = true;
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
                    m_pressed = false;
                    m_onUnPressed();
                }
            }
        }
        return false;
    }
    bool Clickable::pressed()
    {
        return m_isButtonPressed;
    }
    bool Clickable::released()
    {
        return m_isButtonUnpressed;
    }
    bool Clickable::isPressed()
    {
        return m_pressed;
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
