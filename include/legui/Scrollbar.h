#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <legui/Clickable.h>
#include <legui/MouseMoveListener.h>
#include <legui/nano_signal_slot.hpp>

namespace legui {
class Scrollbar : public Clickable {
  public:
  enum Align { Vertical, Horizontal };
  Scrollbar(Container* parent = 0);
  virtual ~Scrollbar();

  virtual void onUpdate(float frametime);
  virtual bool onEvent(const sf::Event& e);
  virtual void setBoundingBox(const sf::FloatRect& box);
  virtual void updateSize();

  void setAlign(Scrollbar::Align align);
  void setScrollSpace(float space);

  Nano::signal<void(float)>& onScrolled();
  float scrolled();

  protected:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
  Nano::signal<void(float)> m_onScrolled;
  sf::RectangleShape* m_bar;
  sf::RectangleShape* m_box;
  sf::VertexArray m_middleLines;

  Scrollbar::Align m_align;
  float m_scrollSpace;
  float m_scrolled;
};
}
