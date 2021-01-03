#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>
#include <legui/FontStyle.h>
#include <legui/Widget.h>

namespace legui {
/**
 * @brief Represents a static line of text.
 */
class Label : public Widget {
  public:
  Label(Container* parent = 0,
        const sf::String& text = "",
        FontStyle style = FontStyle::Regular);
  virtual ~Label();

  virtual void setBoundingBox(const sf::FloatRect& box);
  /**
   * @brief Updates the size of the label & sets the string to fit into the
   * bounding box if LABEL_RECT_BORDER is set to true.
   */
  virtual void updateSize();

  /**
   * @brief Sets the displayed string of the widget.
   *
   * @param text The string to display.
   */
  virtual void setString(const sf::String& text);
  /**
   * @brief Sets the used font of the text.
   *
   * @param font The font.
   */
  virtual void setFont(const sf::Font& font);
  /**
   * @brief Sets an SFML-Style to the font.
   *
   * @param style SFML style.
   */
  virtual void setFontStyle(sf::Text::Style style);
  /**
   * @brief Sets a predefined style to the font.
   *
   * @param style The style.
   */
  virtual void setStyle(FontStyle style);
  /**
   * @brief Sets the character size of the font.
   *
   * @param size THe character size.
   */
  virtual void setCharacterSize(unsigned int size);
  /**
   * @brief Sets the origin of the internal sf::Text. Default is 0, 0.
   *
   * @param origin The origin.
   */
  void setOrigin(const sf::Vector2f& origin);
  /**
   * @brief Sets the width the text should wrap to.
   *
   * If the containing string becomes longer than the given width,
   * a new line will be inserted to split the string in multiple lines to fit
   * the width.
   *
   * @param width The width the text should wrap to.
   */
  void setWrap(float width);
  /**
   * @brief Clears the wrap of the text.
   *
   * No new lines will be inserted and the text will be displayed directly
   * again.
   */
  void clearWrap();
  const sf::String& getString();
  /**
   * @brief If LABEL_RECT_BORDER is set, this is the string in the visible area.
   */
  const sf::String& getVisibleString();
  const sf::Font* getFont();
  sf::Text::Style getFontStyle();
  FontStyle getStyle();
  unsigned int getCharacterSize();
  /**
   * @brief Returns the getLocalBounds() width & height in a vector.
   */
  sf::Vector2f getSize();

  protected:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void updateWrap();

  private:
  sf::Text* m_text;
  sf::String m_string;
  FontStyle m_style;
  float m_wrappingWidth;
  bool m_updateLocally;
};
}
