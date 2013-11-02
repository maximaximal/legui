#include <legui/Checkable.h>

namespace legui
{
    Checkable::Checkable(Container *parent)
        : Clickable(parent)
    {
        m_state = false;
    }
    Checkable::~Checkable()
    {
    
    }

    bool Checkable::isChecked() const
    {
        return m_state;
    }
    void Checkable::D_checked()
    {
        //Derive only!
    }
    void Checkable::D_unchecked()
    {
        //Derive only!
    }
    void Checkable::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        //Nothing to show!
    }
    void Checkable::D_onReleased(const sf::Vector2f &relPos)
    {
        setChecked(!m_state);
    }
    void Checkable::setChecked(bool state)
    {
        m_state = state;
        if(m_state)
        {
            D_checked();
            m_onChecked();
        }
        else
        {
            D_unchecked();
            m_onUnchecked();
        }
    }
    Nano::signal<void()>& Checkable::onChecked()
    {
        return m_onChecked;
    }
    Nano::signal<void()>& Checkable::onUnchecked()
    {
        return m_onUnchecked;
    }
}
