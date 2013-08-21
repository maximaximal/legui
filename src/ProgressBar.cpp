#include <legui/ProgressBar.h>
#include <legui/Config.h>

namespace legui
{
    ProgressBar::ProgressBar(Container *parent)
        : Widget(parent)
    {
        m_leftShape = new sf::RectangleShape();
        m_rightShape = new sf::RectangleShape();

        m_leftShape->setOutlineThickness(Config::getFloat("PROGRESSBAR_OUTLINE_THICKNESS"));
        m_rightShape->setOutlineThickness(Config::getFloat("PROGRESSBAR_OUTLINE_THICKNESS"));
        m_leftShape->setOutlineColor(Config::getColor("PROGRESSBAR_OUTLINE_COLOR"));
        m_rightShape->setOutlineColor(Config::getColor("PROGRESSBAR_OUTLINE_COLOR"));
        m_leftShape->setFillColor(Config::getColor("PROGRESSBAR_FILL_COLOR"));
        m_rightShape->setFillColor(Config::getColor("PROGRESSBAR_FILL_COLOR"));
    }
    ProgressBar::~ProgressBar()
    {
        delete m_leftShape;
        delete m_rightShape;
    }

    void ProgressBar::setBoundingBox(const sf::FloatRect &box)
    {
        Widget::setBoundingBox(box);

        m_leftShape->setSize(sf::Vector2f(box.width / 100 * m_percent, box.height));
        m_leftShape->setPosition(sf::Vector2f(box.left, box.top));
        m_rightShape->setSize(sf::Vector2f(box.width -  (box.width / 100 * m_percent), box.height));
        m_rightShape->setPosition(sf::Vector2f(box.left + m_leftShape->getSize().x, box.top));
    }
    void ProgressBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_leftShape, states);
        target.draw(*m_rightShape, states);
    }
    void ProgressBar::setPercent(float percent)
    {
        m_percent = percent;
    }
    float ProgressBar::getPercent()
    {
        return m_percent;
    }
}
