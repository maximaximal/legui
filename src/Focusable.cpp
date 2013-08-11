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
        //Update the hoverable widget.
        Hoverable::onUpdate(frametime);

        m_focusLost = false;
        m_focusGained = false;
    }
    bool Focusable::onEvent(const sf::Event &e)
    {
        //Update the hoverable widget.
        bool block = Hoverable::onEvent(e);

        if(!block)
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
                            block = true;
                        }
                    }
                }
            }
        }
        return block;
    }
    void Focusable::setFocus(bool state)
    {
        if(m_isFocused)
        {
            if(!state)
            {
                m_focusLost = true;
                m_onFocusLost();
                D_onFocusLost();
            }
        }
        else
        {
            if(state)
            {
                m_focusGained = true;
                m_onFocusGained();
                D_onFocusGained();
            }
        }
        m_isFocused = state;
    }
    void Focusable::setNextFocusable(Focusable *next)
    {
        m_nextFocusable = next;
    }
    bool Focusable::isFocused() const
    {
        return m_isFocused;
    }
    bool Focusable::gainedFox() const
    {
        return m_focusGained;
    }
    bool Focusable::lostFocus() const
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
    void Focusable::D_onFocusGained()
    {
    
    }
    void Focusable::D_onFocusLost()
    {
    
    }
}
