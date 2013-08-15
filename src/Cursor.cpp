#include <legui/Cursor.h>
#include <legui/Config.h>

namespace legui
{
    Cursor::Cursor(Container *parent)
        : Widget(parent)
    {
        m_blinkTimer = 0;
        m_backgroundRect = new sf::RectangleShape();
        m_state = true;
    }
    Cursor::~Cursor()
    {
        delete m_backgroundRect;
    }

    void Cursor::onUpdate(float frametime)
    {
        Widget::onUpdate(frametime);
        m_blinkTimer += frametime;

        if(m_blinkTimer > Config::getFloat("CURSOR_BLINK_RATE"))
        {
            m_state = !m_state;
            this->refresh();
            m_blinkTimer = 0;
        }
    }
    bool Cursor::onEvent(const sf::Event &e)
    {
        Widget::onEvent(e);
        return false;
    }
    void Cursor::setBoundingBox(const sf::FloatRect &box)
    {
        Widget::setBoundingBox(box);
        m_backgroundRect->setPosition(sf::Vector2f(box.left, box.top));
        m_backgroundRect->setSize(sf::Vector2f(Config::getFloat("CURSOR_WIDTH"), box.height));
    }
    void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_backgroundRect, states);
    }
    void Cursor::refresh()
    {
        if(m_state)
            m_backgroundRect->setFillColor(Config::getColor("CURSOR_ACTIVE"));
        else
            m_backgroundRect->setFillColor(Config::getColor("CURSOR_UNACTIVE"));
    }
    void Cursor::resetBlinkTimer()
    {
        m_blinkTimer = 0;
        m_state = true;
        refresh();
    }
}
