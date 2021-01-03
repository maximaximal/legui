#include <legui/CenteredStrip.h>

namespace legui {
CenteredStrip::CenteredStrip(Container* parent)
  : Container(parent) {
  m_elementPadding = 0;
}
CenteredStrip::~CenteredStrip() {}
void
CenteredStrip::setBoundingBox(const sf::FloatRect& box) {
  m_boundingBox = box;
  updateSize();
}
void
CenteredStrip::updateSize() {
  sf::FloatRect middle;
  float y = m_boundingBox.top;
  for(auto& it : m_widgets) {
    middle = it->getBoundingBox();
    middle.left =
      m_boundingBox.left + m_boundingBox.width / 2 - middle.width / 2;
    middle.top = y;
    it->setBoundingBox(middle);
    y += middle.height + m_elementPadding;
  }
}
void
CenteredStrip::setElementPadding(float padding) {
  m_elementPadding = padding;
}
float
CenteredStrip::getElementPadding() {
  return m_elementPadding;
}
}
