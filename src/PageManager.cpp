#include <legui/PageManager.h>

namespace legui
{
    PageManager::PageManager()
    {
        m_currentPage = 0;
        m_screenSizeChanged = false;
        m_updateSizeRequested = false;
    }
    PageManager::~PageManager()
    {
    
    }
    void PageManager::onUpdate(float frametime)
    {
        m_widgets[m_currentPage]->onUpdate(frametime);
    }
    bool PageManager::onEvent(const sf::Event &e)
    {
        return m_widgets[m_currentPage]->onEvent(e);
    }
    void PageManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_widgets[m_currentPage], states);
    }
    void PageManager::setBoundingBox(const sf::FloatRect &box)
    {
        m_widgets[m_currentPage]->setBoundingBox(box);
        m_screenSizeChanged = true;
    }
    void PageManager::updateSize()
    {
        m_widgets[m_currentPage]->updateSize();
        m_updateSizeRequested = true;
        m_boundingBox = m_widgets[m_currentPage]->getBoundingBox();
    }
    void PageManager::push(Container *container)
    {
        m_currentPage = this->addWidget(container);
        container->setBoundingBox(m_boundingBox);
        container->setPageManager(this);
    }
    void PageManager::replaceCurrent(Container *container)
    {
        delete m_widgets[m_currentPage];
        m_widgets[m_currentPage] = container;
        m_widgets[m_currentPage]->setBoundingBox(m_boundingBox);
        container->setPageManager(this);
    }
    void PageManager::popUnder()
    {
        pop(m_currentPage - 1);
    }
    void PageManager::pop(std::size_t page)
    {
        delete m_widgets[page];
        m_widgets.erase(m_widgets.begin() + m_currentPage - 1);
        m_currentPage -= 1;
        if(m_screenSizeChanged)
            top()->setBoundingBox(m_boundingBox);
        if(m_updateSizeRequested)
            top()->updateSize();
        m_screenSizeChanged = false;
        m_updateSizeRequested = false;
    }
    void PageManager::pop()
    {
        pop(m_currentPage);
    }
    Container* PageManager::top()
    {
        return static_cast<Container*>(m_widgets[m_currentPage]);
    }
    Container* PageManager::get(std::size_t page)
    {
        return static_cast<Container*>(m_widgets[page]);
    }
}
