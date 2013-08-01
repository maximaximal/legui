#include <legui/Frame.h>
#include <legui/Config.h>

namespace legui
{
    Frame::Frame(Container *parent)
        : Widget(parent)
    {
        m_rectangleShape = new sf::RectangleShape;

        //Set the colors & the outline thickness from the config.
            setOutlineColor(Config::getColor("FRAME_OUTLINE_COLOR"));
            setFillColor(Config::getColor("FRAME_FILL_COLOR"));
            setOutlineThickness(Config::getFloat("FRAME_OUTLINE_THICKNESS"));
    }
    Frame::~Frame()
    {
        delete m_rectangleShape;
    }
    void Frame::setBoundingBox(const sf::FloatRect &box)
    {
        m_rectangleShape->setPosition(sf::Vector2f(box.left, box.top));
        m_rectangleShape->setSize(sf::Vector2f(box.width, box.height));
    }
    void Frame::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_rectangleShape, states);
    }
    void Frame::setOutlineColor(const sf::Color &color)
    {
        m_rectangleShape->setOutlineColor(color);
    }
    void Frame::setFillColor(const sf::Color &color)
    {
        m_rectangleShape->setFillColor(color);
    }
    void Frame::setOutlineThickness(float thickness)
    {
        m_rectangleShape->setOutlineThickness(thickness);
    }
    const sf::Color& Frame::getOutlineColor()
    {
        return m_rectangleShape->getOutlineColor();
    }
    const sf::Color& Frame::getFillColor()
    {
        return m_rectangleShape->getFillColor();
    }
    float Frame::getOutlineThickness()
    {
        return m_rectangleShape->getOutlineThickness();
    }
};
