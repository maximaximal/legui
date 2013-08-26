#include <legui/Scrollbar.h>
#include <legui/Config.h>

namespace legui
{
    Scrollbar::Scrollbar(Container *parent)
    {
        m_bar = new sf::RectangleShape();
        m_middleLines.setPrimitiveType(sf::PrimitiveType::Lines);
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
        target.draw(m_middleLines, states);
    }
    void Scrollbar::updateSize()
    {
        if(m_align == Align::Vertical)
        {
            m_bar->setSize(sf::Vector2f(m_boundingBox.height / m_scrollSpace * m_boundingBox.height, Config::getFloat("SCROLLBAR_WIDTH")));
            if(Config::getBool("SCROLLBAR_HAS_MIDDLE_LINES"))
            {
                float middle = m_bar->getPosition().y + m_bar->getSize().y / 2;
                m_middleLines.clear();
                m_middleLines.append(sf::Vertex(sf::Vector2f(m_bar->getPosition().x + 2, middle - 2), Config::getColor("SCROLLBAR_GRIP_LINE_COLOR")));
                m_middleLines.append(sf::Vertex(sf::Vector2f(m_bar->getPosition().x + m_bar->getSize().x - 2, middle - 2), Config::getColor("SCROLLBAR_GRIP_LINE_COLOR")));

                m_middleLines.append(sf::Vertex(sf::Vector2f(m_bar->getPosition().x + 2, middle), Config::getColor("SCROLLBAR_GRIP_LINE_COLOR")));
                m_middleLines.append(sf::Vertex(sf::Vector2f(m_bar->getPosition().x + m_bar->getSize().x - 2, middle), Config::getColor("SCROLLBAR_GRIP_LINE_COLOR")));

                m_middleLines.append(sf::Vertex(sf::Vector2f(m_bar->getPosition().x + 2, middle + 2), Config::getColor("SCROLLBAR_GRIP_LINE_COLOR")));
                m_middleLines.append(sf::Vertex(sf::Vector2f(m_bar->getPosition().x + m_bar->getSize().x - 2, middle + 2), Config::getColor("SCROLLBAR_GRIP_LINE_COLOR")));
            }
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
