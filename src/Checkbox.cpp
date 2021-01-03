#include <legui/Checkbox.h>

namespace legui {
Checkbox::Checkbox(Container* parent)
  : Checkable(parent) {
  m_backgroundRect = new sf::RectangleShape();
  m_acceptFoot = new sf::RectangleShape();
  m_acceptShaft = new sf::RectangleShape();
}
Checkbox::~Checkbox() {
  delete m_backgroundRect;
  delete m_acceptShaft;
  delete m_acceptFoot;
}
void
Checkbox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*m_backgroundRect);
  if(isChecked()) {
    target.draw(*m_acceptFoot);
    target.draw(*m_acceptShaft);
  }
}
void
Checkbox::setBoundingBox(const sf::FloatRect& box) {
  Checkable::setBoundingBox(box);
}
void
Checkbox::D_checked() {}
void
Checkbox::D_unchecked() {}
void
Checkbox::onHoverGained() {}
void
Checkbox::onHoverLost() {}
}
