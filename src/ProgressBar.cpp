#include <legui/Config.h>
#include <legui/ProgressBar.h>

namespace legui {
ProgressBar::ProgressBar(Container* parent)
  : Widget(parent) {
  m_percent = 0;
  m_leftShape = new sf::RectangleShape();
  m_rightShape = new sf::RectangleShape();

  m_leftShape->setOutlineThickness(
    Config::getFloat("PROGRESSBAR_OUTLINE_THICKNESS"));
  m_rightShape->setOutlineThickness(
    Config::getFloat("PROGRESSBAR_OUTLINE_THICKNESS"));
  m_leftShape->setOutlineColor(Config::getColor("PROGRESSBAR_OUTLINE_COLOR"));
  m_rightShape->setOutlineColor(Config::getColor("PROGRESSBAR_OUTLINE_COLOR"));
  m_leftShape->setFillColor(Config::getColor("PROGRESSBAR_FILL_COLOR_LEFT"));
  m_rightShape->setFillColor(Config::getColor("PROGRESSBAR_FILL_COLOR_RIGHT"));
}
ProgressBar::~ProgressBar() {
  delete m_leftShape;
  delete m_rightShape;
}

void
ProgressBar::setBoundingBox(const sf::FloatRect& box) {
  Widget::setBoundingBox(box);
  this->updateSize();
}
void
ProgressBar::updateSize() {
  m_leftShape->setSize(
    sf::Vector2f(m_boundingBox.width / 100 * m_percent, m_boundingBox.height));
  m_leftShape->setPosition(sf::Vector2f(m_boundingBox.left, m_boundingBox.top));
  m_rightShape->setSize(
    sf::Vector2f(m_boundingBox.width - (m_boundingBox.width / 100 * m_percent),
                 m_boundingBox.height));
  m_rightShape->setPosition(sf::Vector2f(
    m_boundingBox.left + m_leftShape->getSize().x, m_boundingBox.top));
}
void
ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*m_leftShape, states);
  target.draw(*m_rightShape, states);
}
void
ProgressBar::setPercent(float percent) {
  m_percent = percent;
  this->updateSize();
}
float
ProgressBar::getPercent() {
  return m_percent;
}
}
