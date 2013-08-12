#include <legui/Container.h>
#include <legui/WidgetNotListedException.h>

using namespace std;

namespace legui
{
    Container::Container(Container *parent)
        : Widget(parent)
    {
        m_pageManager = 0;
    }
    Container::~Container()
    {
        this->clear();
    }
    void Container::clear()
    {
        for(auto &it : m_widgets)
        {
            delete it;
        }
        m_widgets.clear();
    }

    void Container::onUpdate(float frametime)
    {
        for(auto &it : m_widgets)
        {
            it->onUpdate(frametime);
        }
    }
    bool Container::onEvent(const sf::Event &e)
    {
        bool block = false;
        for(auto &it : m_widgets)
        {
            if(!block)
                block = it->onEvent(e);
            else
                continue;
        }
        return block;
    }
    void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        for(auto &it : m_widgets)
        {
            target.draw(*it, states);
        }
    }
    void Container::updateSize()
    {
        m_boundingBox.width = 0;
        m_boundingBox.height = 0;
        for(auto &it : m_widgets)
        {
            m_boundingBox.width += it->getBoundingBox().width;
            m_boundingBox.height += it->getBoundingBox().height;
        }
    }
    std::size_t Container::addWidget(Widget *widget)
    {
        m_widgets.push_back(widget); 
        return m_widgets.size() - 1;
    }
    void Container::deleteWidget(Widget *widget)
    {
        for(auto it = m_widgets.begin(); it != m_widgets.end(); ++it)
        {
            if((*it) == widget)
            {
                delete (*it);
                m_widgets.erase(it);
                return;
            }
        }
        throw(WidgetNotListedException());
    }
    void Container::deleteWidget(std::size_t widget)
    {
        if(widget < m_widgets.size())
        {
            delete m_widgets[widget];
            m_widgets.erase(m_widgets.begin() + widget);
        }
        else
        {
            throw(WidgetNotListedException());
        }
    }
    void Container::removeWidget(Widget *widget)
    {
        for(auto it = m_widgets.begin(); it != m_widgets.end(); ++it)
        {
            if((*it) == widget)
            {
                m_widgets.erase(it);
                return;
            }
        }
        throw(WidgetNotListedException());
    }
    void Container::removeWidget(std::size_t widget)
    {
        if(widget < m_widgets.size())
        {
            m_widgets.erase(m_widgets.begin() + widget);
        }
        else
        {
            throw(WidgetNotListedException());
        }
    }
    void Container::setPageManager(PageManager *pageManager)
    {
        m_pageManager = pageManager;
    }
    std::vector<Widget*>& Container::getWidgets()
    {
        return m_widgets;
    }
    std::size_t Container::getSize()
    {
        return m_widgets.size();
    }
    PageManager* Container::getPageManager()
    {
        return m_pageManager;
    }
}
