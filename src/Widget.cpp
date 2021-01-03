#include <legui/Container.h>
#include <legui/Widget.h>

namespace legui {
Widget::Widget(Container* parent) {
  m_parent = 0;
  setParent(parent);
}
Widget::~Widget() {}
void
Widget::removeFromParent() {
  if(m_parent)
    m_parent->removeWidget(m_parentIt);
}
void
Widget::onUpdate(float frametime) {}
bool
Widget::onEvent(const sf::Event& e) {
  return false;
}
void
Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const {}
void
Widget::setBoundingBox(const sf::FloatRect& box) {
  m_boundingBox = box;
}
void
Widget::updateSize() {}
void
Widget::setParent(Container* parent) {
  if(m_parent != 0)
    m_parent->removeWidget(this);
  m_parent = parent;
}
Container*
Widget::getParent() {
  return m_parent;
}
const sf::FloatRect&
Widget::getBoundingBox() {
  return m_boundingBox;
}
}
