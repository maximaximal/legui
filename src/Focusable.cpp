#include <legui/Focusable.h>

namespace legui
{
    Focusable::Focusable(Container *parent)
        : Hoverable(parent)
    {
        m_focusLost = false;
        m_focusGained = false;
        m_isFocused = false;
        m_nextFocusable = 0;
    }
    void Focusable::onUpdate(float frametime)
    {
        m_focusLost = false;
        m_focusGained = false;
    }
    bool Focusable::onEvent(const sf::Event &e)
    {
        if(e.type == sf::Event::KeyPressed)
        {
            if(isFocused())
            {
                if(e.key.code == sf::Keyboard::Tab)
                {
                    if(m_nextFocusable != 0)
                    {
                        m_nextFocusable->setFocus(true);
                        this->setFocus(false);
                    }
                }
            }
        }
        return false;
    }
    void Focusable::setFocus(bool state)
    {
        m_isFocused = state;
        if(state)
        {
            m_focusGained = true;
            m_onFocusGained();
        }
        else
        {
            m_focusLost = true;
            m_onFocusLost();
        }
    }
    void Focusable::setNextFocusable(Focusable *next)
    {
        m_nextFocusable = next;
    }
    bool Focusable::isFocused()
    {
        return m_isFocused;
    }
    bool Focusable::gainedFox()
    {
        return m_focusGained;
    }
    bool Focusable::lostFocus()
    {
        return m_focusLost;
    }
    Nano::signal<void()>& Focusable::onFocusGained()
    {
        return m_onFocusGained;
    }
    Nano::signal<void()>& Focusable::onFocusLost()
    {
        return m_onFocusLost;
    }
}
