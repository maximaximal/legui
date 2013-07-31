#include <legui/Widget.h>
#include <legui/Container.h>

namespace legui
{
    Widget::Widget(Container* parent)
    {
        setParent(parent);
    }
    Widget::~Widget()
    {
        if(m_parent)
            m_parent->updateSize();
        m_parent->removeWidget(m_parentIt);
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
    void Widget::setParent(Container *parent)
    {
        m_parent = parent;
        m_parentIt = parent->addWidget(this);
    }
    Container* Widget::getParent()
    {
        return m_parent;
    }
    const sf::FloatRect& Widget::getBoundingBox()
    {
        return m_boundingBox;
    }
};
