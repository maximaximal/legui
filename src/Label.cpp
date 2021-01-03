#include <algorithm>
#include <iostream>
#include <iterator>
#include <legui/Config.h>
#include <legui/Container.h>
#include <legui/FontManagerAbstract.h>
#include <legui/Label.h>
#include <sstream>
#include <string>

using namespace std;

namespace legui {
Label::Label(Container* parent, const sf::String& text, FontStyle style)
  : Widget(parent) {
  m_text = new sf::Text();
  m_wrappingWidth = 0;
  m_updateLocally = false;
  this->setString(text);
  this->setStyle(style);
}
Label::~Label() {
  delete m_text;
}

void
Label::setStyle(FontStyle style) {
  FontStyleUtils::setStyle(m_text, style);
  this->updateSize();
}
void
Label::setBoundingBox(const sf::FloatRect& box) {
  Widget::setBoundingBox(box);
  m_boundingBox.width = m_text->getGlobalBounds().width;
  m_boundingBox.height = m_text->getGlobalBounds().height;

  if(Config::getBool("LABEL_PIXELPERFECT_POSITION"))
    m_text->setPosition(sf::Vector2f(
      (int)box.left, (int)(box.top - m_boundingBox.height * 0.25)));
  else
    m_text->setPosition(
      sf::Vector2f(box.left, box.top - m_boundingBox.height * 0.25));

  this->updateWrap();
}
void
Label::updateSize() {
  if(Config::getBool("LABEL_RECT_BORDER")) {
    sf::String currentlyVisible("");
    for(std::size_t i = 0; i < m_text->getString().getSize(); ++i) {
      if(m_text->findCharacterPos(i).x >
         m_boundingBox.left + m_boundingBox.width) {
        m_text->setString(currentlyVisible);
        continue;
      }
      currentlyVisible += m_text->getString()[i];
    }
    m_text->setString(currentlyVisible);
  }
  m_boundingBox.width = m_text->getGlobalBounds().width;
  m_boundingBox.height = m_text->getGlobalBounds().height;
  if(m_parent != 0) {
    if(m_updateLocally == false)
      m_parent->updateSize();
    else
      m_updateLocally = false;
  }
}
void
Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*m_text, states);
}
void
Label::setCharacterSize(unsigned int size) {
  m_text->setCharacterSize(size);
  updateWrap();
  this->updateSize();
}
void
Label::setFont(const sf::Font& font) {
  m_text->setFont(font);
  updateWrap();
  this->updateSize();
}
void
Label::setString(const sf::String& text) {
  m_text->setString(text);
  updateWrap();
  m_string = text;
  this->updateSize();
}
void
Label::setFontStyle(sf::Text::Style style) {
  m_text->setStyle(style);
  updateWrap();
  this->updateSize();
}
void
Label::setOrigin(const sf::Vector2f& origin) {
  m_text->setOrigin(origin);
}
const sf::String&
Label::getVisibleString() {
  return m_text->getString();
}
const sf::String&
Label::getString() {
  return m_string;
}
const sf::Font*
Label::getFont() {
  return m_text->getFont();
}
sf::Text::Style
Label::getFontStyle() {
  return static_cast<sf::Text::Style>(m_text->getStyle());
}
FontStyle
Label::getStyle() {
  return m_style;
}
unsigned int
Label::getCharacterSize() {
  return m_text->getCharacterSize();
}
sf::Vector2f
Label::getSize() {
  return sf::Vector2f(m_text->getLocalBounds().width,
                      m_text->getLocalBounds().height);
}
void
Label::setWrap(float width) {
  m_wrappingWidth = width;
  this->updateWrap();
  // cout << "WRAP: " << width << endl;
}
void
Label::updateWrap() {
  if(m_wrappingWidth == 0) {
    // No wrapping neccessary - deactivated
  } else {
    float lineWidth = 0;
    sf::String out;
    std::vector<std::string> words;
    std::stringstream ss(m_string.toAnsiString());
    std::string item;
    char delim = 32;// Space
    bool bold = false;
    if(m_text->getStyle() & sf::Text::Bold)
      bold = true;
    while(std::getline(ss, item, delim)) {
      words.push_back(item);
    }
    for(std::size_t i = 0; i < words.size(); ++i) {
      float width = 0;
      bool lineFlag = true;
      for(std::size_t j = 0; j < words[i].size(); ++j) {
        sf::Glyph glyph = m_text->getFont()->getGlyph(
          words[i][j], m_text->getCharacterSize(), bold);
        width += glyph.advance;
      }
      lineWidth += width;
      if(lineWidth >= m_wrappingWidth && lineFlag) {
        out += "\n" + words[i] + " ";
        lineWidth = 0;
        lineFlag = false;
      } else {
        out += words[i] + " ";
        lineFlag = true;
      }
    }
    m_text->setString(out);
  }
}
}
