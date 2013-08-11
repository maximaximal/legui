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
                    m_relPos = sf::Vector2f(0, 0);
                    setPressed(true);
                }
            }
            if(e.type == sf::Event::KeyReleased)
            {
                if(e.key.code == sf::Keyboard::Return)
                {
                    m_relPos = sf::Vector2f(0, 0);
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
                    m_relPos = sf::Vector2f(e.mouseButton.x, e.mouseButton.y) - sf::Vector2f(m_boundingBox.left, m_boundingBox.top);
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
                    m_relPos = sf::Vector2f(e.mouseButton.x, e.mouseButton.y) - sf::Vector2f(m_boundingBox.left, m_boundingBox.top);
                    setPressed(false);
                }
            }
        }
        return false;
    }
    const sf::Vector2f& Clickable::getRelPos()
    {
        return m_relPos;
    }
    void Clickable::setPressed(bool state)
    {
        if(m_pressed)
        {
            if(!state)
            {
                m_isButtonUnpressed = true;
                m_onUnPressed.emit(m_relPos);
                D_onReleased(m_relPos);
            }
        }
        else
        {
            if(state)
            {
                m_isButtonPressed = true;
                m_onPressed.emit(m_relPos);
                D_onClicked(m_relPos);
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
    Nano::signal<void(const sf::Vector2f&)>& Clickable::onPressed()
    {
        return m_onPressed;
    }
    Nano::signal<void(const sf::Vector2f&)>& Clickable::onUnPressed()
    {
        return m_onUnPressed;
    }
    void Clickable::D_onClicked(const sf::Vector2f &relPos)
    {
    
    }
    void Clickable::D_onReleased(const sf::Vector2f &relPos)
    {
    
    }
}
