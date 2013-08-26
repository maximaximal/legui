#include <legui/Scrollable.h>

namespace legui
{
    Scrollable::Scrollable(const sf::Vector2u &screenSize, Container *parent)
        : Container(parent)
    {
        m_hBar = new Scrollbar();
        m_vBar = new Scrollbar();
        m_view = new sf::View();
        m_screenSize = screenSize;
    }
    Scrollable::~Scrollable()
    {
        delete m_hBar;
        delete m_vBar;
        delete m_view;
    }
    bool Scrollable::onEvent(const sf::Event &e)
    {
        //Self-Update the internal screen size.
        if(e.type == sf::Event::Resized)
        {
            m_screenSize.x = e.size.width;
            m_screenSize.y = e.size.height;
        }
        bool block = false;
        if(m_hBarActive)
            block = m_hBar->onEvent(e);
        if(!block)
            if(m_vBarActive)
                block = m_vBar->onEvent(e);
        
        if(!block)
        {
            //Converts the mouse position of the event (relative to the window)
            //to be relative to the scrollable (includes the current offset of the scrollable).
            
            sf::Event viewEvent = e;
            switch(viewEvent.type)
            {
                case sf::Event::MouseMoved:
                    viewEvent.mouseMove.x += m_offset.x - m_boundingBox.left;
                    viewEvent.mouseMove.y += m_offset.y - m_boundingBox.top;
                    break;
                case sf::Event::MouseButtonPressed:
                    viewEvent.mouseButton.x += m_offset.x - m_boundingBox.left;
                    viewEvent.mouseMove.y += m_offset.y - m_boundingBox.top;
                    break;
                case sf::Event::MouseButtonReleased:
                    viewEvent.mouseButton.x += m_offset.x - m_boundingBox.left;
                    viewEvent.mouseButton.y += m_offset.y - m_boundingBox.top;
                    break;
                case sf::Event::MouseWheelMoved:
                    viewEvent.mouseWheel.x += m_offset.x - m_boundingBox.left;
                    viewEvent.mouseWheel.y += m_offset.y - m_boundingBox.top;
                    break;
            };
            block = Container::onEvent(viewEvent);
        }
        return block;
    }
    void Scrollable::setBoundingBox(const sf::FloatRect &box)
    {
        m_boundingBox = box;
        this->updateSize();
    }
    void Scrollable::updateSize()
    {
        //Compute the internal size of widgets
        sf::Vector2f internSize;
        sf::FloatRect cacheBox;
        for(auto &it : m_widgets)
        {
            cacheBox = it->getBoundingBox();
            if(cacheBox.left + cacheBox.width > internSize.x)
                internSize.x = cacheBox.left + cacheBox.width;
            if(cacheBox.top + cacheBox.height > internSize.y)
                internSize.y = cacheBox.top + cacheBox.height;
        }
        m_internSize = internSize;

        //Check if the scrollable needs scrollbars.
        if(internSize.x > m_boundingBox.width)
            m_vBarActive = true;
        else
            m_vBarActive = false;
        if(internSize.y > m_boundingBox.height)
            m_hBarActive = true;
        else
            m_hBarActive = false;
    
        this->updateView();
    }
    void Scrollable::updateView()
    {
        //Update the internal view
        m_view->reset(sf::FloatRect(m_offset.x, m_offset.y, m_boundingBox.width, m_boundingBox.height));
        m_view->setViewport(sf::FloatRect(m_boundingBox.left / m_screenSize.x, 
                                          m_boundingBox.top / m_screenSize.y, 
                                          m_boundingBox.width / m_screenSize.x, 
                                          m_boundingBox.height / m_screenSize.y));
    
    }
    void Scrollable::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        if(m_hBarActive)
            target.draw(*m_hBar, states);
        if(m_vBarActive)
            target.draw(*m_vBar, states);

        const sf::View &oldView = target.getView();
        target.setView(*m_view);
        for(auto &it : m_widgets)
        {
            target.draw(*it, states);
        }
        target.setView(oldView);
    }
    void Scrollable::setHScroll(float scroll)
    {
        m_offset.x = scroll;
        this->updateView();
    }
    void Scrollable::setVScroll(float scroll)
    {
        m_offset.y = scroll;
        this->updateView();
    }
}
