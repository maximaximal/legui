#include <legui/Scrollbar.h>
#include <legui/Config.h>

namespace legui
{
    Scrollbar::Scrollbar(Container *parent)
        : Clickable(parent)
    {
        m_bar = new sf::RectangleShape();
        m_box = new sf::RectangleShape();
    }
    Scrollbar::~Scrollbar()
    {
        delete m_bar;
    }
    void Scrollbar::onUpdate(float frametime)
    {
        Clickable::onUpdate(frametime);
        m_scrolled = 0;
    }
    bool Scrollbar::onEvent(const sf::Event &e)
    {
        Clickable::onEvent(e);
    }
    void Scrollbar::setBoundingBox(const sf::FloatRect &box)
    {
        Clickable::setBoundingBox(box);
    }
    void Scrollbar::setScrollSpace(float space)
    {
        m_scrollSpace = space;
    }
    void Scrollbar::setAlign(Scrollbar::Align align)
    {
        m_align = align;
        this->updateSize();
    }
    void Scrollbar::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_box, states);
        target.draw(*m_bar, states);
    }
    void Scrollbar::updateSize()
    {
        if(m_align == Align::Vertical)
        {

        }
    }
    Nano::signal<void(float)>& Scrollbar::onScrolled()
    {
        return m_onScrolled;
    }
    float Scrollbar::scrolled()
    {
        return m_scrolled;
    }
}
