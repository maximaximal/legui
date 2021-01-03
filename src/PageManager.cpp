#include <legui/PageManager.h>

namespace legui {
PageManager::PageManager() {
  m_currentPage = 0;
  m_screenSizeChanged = false;
  m_updateSizeRequested = false;
  m_popFlag = false;
}
PageManager::~PageManager() {}
void
PageManager::onUpdate(float frametime) {
  if(m_currentPage < m_widgets.size())
    m_widgets[m_currentPage]->onUpdate(frametime);
  if(m_popFlag) {
    if(m_currentPage < m_widgets.size())
      pop(m_currentPage);
    m_popFlag = false;
  }
}
bool
PageManager::onEvent(const sf::Event& e) {
  if(m_currentPage < m_widgets.size())
    return m_widgets[m_currentPage]->onEvent(e);
  else
    return false;
}
void
PageManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  if(m_currentPage < m_widgets.size())
    target.draw(*m_widgets[m_currentPage], states);
}
void
PageManager::setBoundingBox(const sf::FloatRect& box) {
  Container::setBoundingBox(box);
  for(auto& it : m_widgets) {
    it->setBoundingBox(box);
  }
}
void
PageManager::updateSize() {
  if(m_currentPage < m_widgets.size()) {
    m_widgets[m_currentPage]->updateSize();
    m_boundingBox = m_widgets[m_currentPage]->getBoundingBox();
  }
  m_updateSizeRequested = true;
}
void
PageManager::push(Container* container) {
  m_currentPage = this->addWidget(container);
  container->setBoundingBox(m_boundingBox);
  container->setPageManager(this);
}
void
PageManager::replaceCurrent(Container* container) {
  if(m_currentPage < m_widgets.size()) {
    delete m_widgets[m_currentPage];
    m_widgets[m_currentPage] = container;
    m_widgets[m_currentPage]->setBoundingBox(m_boundingBox);
    container->setPageManager(this);
  } else {
    this->push(container);
  }
}
void
PageManager::popUnder() {
  if(m_currentPage > 1 && m_currentPage < m_widgets.size())
    pop(m_currentPage - 1);
}
void
PageManager::pop(std::size_t page) {
  delete m_widgets[page];
  m_widgets.erase(m_widgets.begin() + m_currentPage);
  if(m_currentPage > 0) {
    m_currentPage -= 1;
    if(m_screenSizeChanged)
      top()->setBoundingBox(m_boundingBox);
    if(m_updateSizeRequested)
      top()->updateSize();
    m_screenSizeChanged = false;
    m_updateSizeRequested = false;
  }
}
void
PageManager::pop() {
  m_popFlag = true;
}
Container*
PageManager::top() {
  return static_cast<Container*>(m_widgets[m_currentPage]);
}
Container*
PageManager::get(std::size_t page) {
  return static_cast<Container*>(m_widgets[page]);
}
}
