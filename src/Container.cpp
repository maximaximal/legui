#include <legui/Container.h>
#include <legui/WidgetNotListedException.h>

using namespace std;

namespace legui {
Container::Container(Container* parent)
  : Widget(parent) {
  m_pageManager = 0;
}
Container::~Container() {
  this->clear();
}
void
Container::clear() {
  for(auto& it : m_widgets) {
    D_widgetRemoved(it);
    delete it;
  }
  m_widgets.clear();
}

void
Container::onUpdate(float frametime) {
  for(auto& it : m_widgets) {
    it->onUpdate(frametime);
  }
}
bool
Container::onEvent(const sf::Event& e) {
  bool block = false;
  for(auto& it : m_widgets) {
    if(!block)
      block = it->onEvent(e);
    else
      continue;
  }
  return block;
}
void
Container::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for(auto& it : m_widgets) {
    target.draw(*it, states);
  }
}
void
Container::updateSize() {
  for(auto& it : m_widgets) {
    it->updateSize();
  }
}
std::size_t
Container::addWidget(Widget* widget) {
  m_widgets.push_back(widget);
  widget->setParent(this);
  return m_widgets.size() - 1;
  D_widgetAdded(widget);
}
void
Container::deleteWidget(Widget* widget) {
  for(auto it = m_widgets.begin(); it != m_widgets.end(); ++it) {
    if((*it) == widget) {
      delete(*it);
      m_widgets.erase(it);
      return;
    }
  }
  throw(WidgetNotListedException());
}
void
Container::deleteWidget(std::size_t widget) {
  if(widget < m_widgets.size()) {
    this->D_widgetRemoved(m_widgets[widget]);
    delete m_widgets[widget];
    m_widgets.erase(m_widgets.begin() + widget);
  } else {
    throw(WidgetNotListedException());
  }
}
void
Container::removeWidget(Widget* widget) {
  for(auto it = m_widgets.begin(); it != m_widgets.end(); ++it) {
    if((*it) == widget) {
      m_widgets.erase(it);
      return;
    }
  }
  throw(WidgetNotListedException());
}
void
Container::removeWidget(std::size_t widget) {
  if(widget < m_widgets.size()) {
    legui::Widget* w = m_widgets[widget];
    m_widgets.erase(m_widgets.begin() + widget);
    this->D_widgetRemoved(w);
  } else {
    throw(WidgetNotListedException());
  }
}
void
Container::setPageManager(PageManager* pageManager) {
  m_pageManager = pageManager;
}
std::vector<Widget*>&
Container::getWidgets() {
  return m_widgets;
}
std::size_t
Container::getSize() {
  return m_widgets.size();
}
PageManager*
Container::getPageManager() {
  return m_pageManager;
}
void
Container::D_widgetRemoved(Widget* widget) {}
void
Container::D_widgetAdded(Widget* widget) {}
}
