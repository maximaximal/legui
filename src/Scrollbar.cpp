#include <legui/Scrollbar.h>

namespace legui
{
    Scrollbar::Scrollbar(Container *parent)
    {
        m_bar = 0;
    }
    Scrollbar::~Scrollbar()
    {
        delete m_bar;
    }

    void Scrollbar::onUpdate(float frametime)
    {
        Clickable::onUpdate(frametime);
        MouseMoveListener::onUpdate(frametime);
    }
    void Scrollbar::onEvent(const sf::Event &e)
    {
        Clickable::onEvet(e);
        MouseMoveListener::onEvent(e);
    }
    void Scrollbar::setBoundingBox(const sf::FloatRect &box)
    {
        Clickable::setBoundingBox(box);
        MouseMoveListener::setBoundingBox(box);
    }
    void Scrollbar::updateSize()
    {
        Clickable::updateSize();
        MouseMoveListener::updateSize();
    }
    void Scrollbar::setScrollable(Scrollbar *scrollable)
    {
        m_scrollable = scrollable;
        m_scrollArea = m_scrollable->getScrollArea();
        this->setBoundingBox(m_scrollable->getBoundingBox());
    }
    void Scrollbar::updateBox()
    {
        if(m_align == Align::Vertical)
        {
            m_bar->setSize(sf::Vector2f(m_boundingBox.height / m_scrollArea.y * m_boundingBox.height, Config::getFloat("SCROLLBAR_WIDTH")));
            if(Config::getBool("SCROLLBAR_HAS_MIDDLE_LINES"))
            {
                float middle = m_bar->getSize().y / 2.
                //TODO Complete this!
            }
        }
    }
}
