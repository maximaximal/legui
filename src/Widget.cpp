#include <legui/Widget.h>

namespace legui
{
    Widget::Widget(Widget* parent)
    {
        setParent(parent);
    }
    Widget::~Widget()
    {
        if(m_parent)
            m_parent->updateSize();
    }
    
    void Widget::onUpdate(float frametime)
    {
    
    }
    bool Widget::onEvent(const sf::Event &e)
    {
        return false;
    }
    void Widget::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
    
    }
    void Widget::setBoundingBox(const sf::FloatRect &box)
    {
    
    }
    void Widget::updateSize()
    {
    
    }
    void Widget::setParent(legui::Widget *parent)
    {
        m_parent = parent;
    }
    Widget *Widget::getParent()
    {
        return m_parent;
    }
    const sf::FloatRect& Widget::getBoundingBox()
    {
        return m_boundingBox;
    }
};
