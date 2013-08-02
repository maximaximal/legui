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
        //Update the focusable widget.
        Focusable::onUpdate(frametime);

        m_isButtonPressed = false;
        m_isButtonUnpressed = false;
    }
    bool Clickable::onEvent(const sf::Event &e)
    {
        //Update the focusable widget.
        Focusable::onEvent(e);
        
        if(isFocused())
        {
            if(e.type == sf::Event::KeyPressed)
            {
                if(e.key.code == sf::Keyboard::Return)
                {
                    setPressed(true);
                }
            }
            if(e.type == sf::Event::KeyReleased)
            {
                if(e.key.code == sf::Keyboard::Return)
                {
                    setPressed(false);
                }
            }
        }
        if(e.type == sf::Event::MouseButtonPressed)
        {
            if(e.mouseButton.button == sf::Mouse::Left)
            {
                if(m_boundingBox.contains(e.mouseButton.x, e.mouseButton.y))
                {
                    setPressed(true);
                }
            }
        }
        if(e.type == sf::Event::MouseButtonReleased)
        {
            if(e.mouseButton.button == sf::Mouse::Left)
            {
                if(m_boundingBox.contains(e.mouseButton.x, e.mouseButton.y))
                {
                    setPressed(false);
                }
            }
        }
        return false;
    }
    void Clickable::setPressed(bool state)
    {
        if(m_pressed)
        {
            if(!state)
            {
                m_isButtonUnpressed = true;
                m_onUnPressed();
            }
        }
        else
        {
            if(state)
            {
                m_isButtonPressed = true;
                m_onPressed();
            }
        }
        m_pressed = state;
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
