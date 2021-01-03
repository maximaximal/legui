#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <legui/Checkable.h>

namespace legui {
class Checkbox : public Checkable {
  public:
  Checkbox(Container* parent);
  virtual ~Checkbox();

  virtual void setBoundingBox(const sf::FloatRect& box);

  protected:
  virtual void D_checked();
  virtual void D_unchecked();
  virtual void D_onHoverGained();
  virtual void D_onHoverLost();

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
  // The background rectangle.
  sf::RectangleShape* m_backgroundRect;
  // The foot of the symbol.
  sf::RectangleShape* m_acceptFoot;
  // The shaft of the accept symbol.
  sf::RectangleShape* m_acceptShaft;
};
}
