#pragma once

#include <legui/Container.h>

namespace legui {
/**
 * @brief Centers the containing elements in the middle of its bounding box.
 *
 * The element sizes aren't changed, only their positions!
 */
class CenteredStrip : public Container {
  public:
  CenteredStrip(Container* parent = 0);
  virtual ~CenteredStrip();
  /**
   * @brief Only alignes the elements, doesn't give them a new size!
   */
  virtual void setBoundingBox(const sf::FloatRect& box);
  virtual void updateSize();
  /**
   * @brief Sets the space between each element.
   *
   * @param padding The padding in pixels.
   */
  void setElementPadding(float padding);
  float getElementPadding();

  private:
  float m_elementPadding;
};
}
