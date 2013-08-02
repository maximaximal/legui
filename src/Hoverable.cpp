#include <legui/Hoverable.h>

namespace legui
{
    Hoverable::Hoverable(Container *parent)
        : Widget(parent)
    {
        m_hoverGained = false;
        m_hoverLost = false;
        m_hover = false;
    }
    void Hoverable::onUpdate(float frametime)
    {
        m_hoverGained = false;
        m_hoverLost = false;
    }
    bool Hoverable::onEvent(const sf::Event &e)
    {
        if(e.type == sf::Event::MouseMoved)
        {
            if(m_boundingBox.contains(e.mouseMove.x, e.mouseMove.y))
            {
                setHover(true);
            }
            else
            {
                setHover(false);
            }
        }
        return false;
    }
    bool Hoverable::isHovered()
    {
        return m_hover;
    }
    bool Hoverable::hoverGained()
    {
        return m_hoverGained;
    }
    bool Hoverable::hoverLost()
    {
        return m_hoverLost;
    }
    Nano::signal<void()>& Hoverable::onHoverGained()
    {
        return m_onHoverGained;
    }
    Nano::signal<void()>& Hoverable::onHoverLost()
    {
        return m_onHoverLost;
    }
    void Hoverable::setHover(bool state)
    {
        if(m_hover)
        {
            if(!state)
            {
                m_onHoverLost();
                m_hoverLost = true;
            }
        }
        else
        {
            if(state)
            {
                m_onHoverGained();
                m_hoverGained = true;
            }
        }
        m_hover = state;
    }
}
