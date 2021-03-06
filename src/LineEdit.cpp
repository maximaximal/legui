#include <legui/Config.h>
#include <legui/FontManagerAbstract.h>
#include <legui/LineEdit.h>

#include <iostream>
using namespace std;

namespace legui {
LineEdit::LineEdit(Container* parent)
  : Clickable(parent) {
  m_cursor = new Cursor();
  m_frame = new Frame();
  m_style = FontStyle::Regular;
  m_fontStyle = sf::Text::Style::Regular;
  m_characterSize = Config::getInt("DEFAULT_FONT_SIZE");
  m_color = Config::getColor("DEFAULT_FONT_COLOR");
  m_fontPath = Config::getString("DEFAULT_FONT");
  m_cursorPos = 0;
  m_xOffset = 0;
  m_hasChanged = false;
  m_isFinished = false;
  m_queryCursorUpdate = false;
}
LineEdit::~LineEdit() {
  clear();
  delete m_cursor;
  delete m_frame;
}
void
LineEdit::clear() {
  for(auto& it : m_letters) {
    delete it;
  }
  m_letters.clear();
  m_string = "";
  m_cursorPos = 0;
  m_xOffset = 0;
  m_hasChanged = false;
  m_isFinished = false;
  m_queryCursorUpdate = false;
  updateCursorPos();
}

void
LineEdit::onUpdate(float frametime) {
  Clickable::onUpdate(frametime);
  m_frame->onUpdate(frametime);
  m_cursor->onUpdate(frametime);
  m_hasChanged = false;
  m_isFinished = false;
  if(m_queryCursorUpdate) {
    this->updateCursorPos();
    m_cursor->resetBlinkTimer();
    m_queryCursorUpdate = false;
  }
}
bool
LineEdit::onEvent(const sf::Event& e) {
  bool block = Clickable::onEvent(e);
  if(!block) {
    m_frame->onEvent(e);
    if(this->isFocused()) {
      m_cursor->onEvent(e);
      if(e.type == sf::Event::KeyPressed) {
        if(e.key.code == sf::Keyboard::Left) {
          if(m_cursorPos > 0)
            m_cursorPos -= 1;
          updateCursorPos();
          block = true;
          m_cursor->resetBlinkTimer();
        }
        if(e.key.code == sf::Keyboard::Right) {
          if(m_cursorPos < m_string.getSize())
            m_cursorPos += 1;
          updateCursorPos();
          block = true;
          m_cursor->resetBlinkTimer();
        }
      }
      if(e.type == sf::Event::TextEntered) {
        this->appendCharacter(e.text.unicode);
        updateLetterPos();
        updateCursorPos();
        block = true;
        m_cursor->resetBlinkTimer();
        m_hasChanged = true;
        m_onChanged(m_string);
      }
    }
  }
  return block;
}
void
LineEdit::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*m_frame, states);
  for(auto& it : m_letters) {
    if(it->getPosition().x >= Clickable::m_boundingBox.left &&
       it->getPosition().x + it->getGlobalBounds().width <=
         Clickable::m_boundingBox.left + Clickable::m_boundingBox.width)
      target.draw(*it, states);
  }
  if(this->isFocused())
    target.draw(*m_cursor, states);
}
void
LineEdit::setBoundingBox(const sf::FloatRect& box) {
  Clickable::setBoundingBox(box);
  m_frame->setBoundingBox(box);
  m_characterSize = (unsigned int)box.height;
  updateLetterPos();
  updateCursorPos();
}
void
LineEdit::updateSize() {
  Clickable::updateSize();
  m_frame->updateSize();
  m_cursor->updateSize();
}
void
LineEdit::D_onClicked(const sf::Vector2f& relPos) {
  float x = 0;
  for(std::size_t i = 0; relPos.x > x && i < m_letters.size(); ++i) {
    x += m_letters[i]->getGlobalBounds().width;
    m_cursorPos = i;
  }
  if(m_letters.size() > 0) {
    if(relPos.x > x) {
      ++m_cursorPos;
    }
  }
  this->updateCursorPos();
  m_cursor->resetBlinkTimer();
}
void
LineEdit::D_onFocusGained() {
  m_queryCursorUpdate = true;
}
void
LineEdit::D_onFocusLost() {
  if(!m_isFinished)
    m_onFinished(m_string);
  m_isFinished = true;
}
void
LineEdit::updateLetterPos() {
  // Update letter positions
  float kerning = 0;
  float x = m_boundingBox.left;
  const sf::Font& font = Config::getFontManager()->get(m_fontPath);
  for(std::size_t i = 0; i < m_letters.size(); ++i) {
    if(i > 0) {
      kerning = font.getKerning(m_letters[i - 1]->getString().getData()[0],
                                m_letters[i]->getString().getData()[0],
                                m_characterSize);
      x += m_letters[i - 1]->getGlobalBounds().width + kerning;
    }
    m_letters[i]->setPosition(
      sf::Vector2f(x + m_xOffset, Clickable::m_boundingBox.top));
  }
}
void
LineEdit::updateCursorPos() {
  if(m_letters.size() > 0 && m_cursorPos > 0) {
    if(m_letters[m_cursorPos - 1]->getGlobalBounds().left <
       m_boundingBox.left) {
      m_xOffset += m_letters[m_cursorPos - 1]->getGlobalBounds().width;
      if(m_cursorPos == 1)
        m_xOffset = 0;
      this->updateLetterPos();
    } else if(m_letters[m_cursorPos - 1]->getGlobalBounds().left +
                m_letters[m_cursorPos - 1]->getGlobalBounds().width >
              m_boundingBox.left + m_boundingBox.width) {
      m_xOffset -= m_letters[m_cursorPos - 1]->getGlobalBounds().width;
      this->updateLetterPos();
    }
  }
  if(m_cursorPos != 0) {
    this->applyStyle();
    float x = m_letters[m_cursorPos - 1]->getGlobalBounds().width +
              m_letters[m_cursorPos - 1]->getPosition().x;
    m_cursor->setBoundingBox(
      sf::FloatRect(x, Clickable::m_boundingBox.top, 2, m_boundingBox.height));
  } else
    m_cursor->setBoundingBox(sf::FloatRect(Clickable::m_boundingBox.left,
                                           Clickable::m_boundingBox.top,
                                           2,
                                           m_boundingBox.height));
}
void
LineEdit::setString(const sf::String& text) {
  clear();
  for(std::size_t i = 0; i < text.getSize(); ++i) {
    this->appendCharacter(text[i]);
  }
  m_queryCursorUpdate = true;
}
void
LineEdit::appendCharacter(sf::Uint32 character) {
  if(character == 8)// Character equals a backspace
  {
    if(m_cursorPos > 0) {
      m_string.erase(m_cursorPos - 1);
      delete m_letters[m_cursorPos - 1];
      m_letters.erase(m_letters.begin() + m_cursorPos - 1);
      m_cursorPos--;
    }
  } else if(character == 127)// Delete character
  {
    if(m_cursorPos < m_string.getSize()) {
      m_string.erase(m_cursorPos);
      delete m_letters[m_cursorPos];
      m_letters.erase(m_letters.begin() + m_cursorPos);
    }
  } else if(character == 13) {
    this->focusToNext();
    m_isFinished = true;
    m_onFinished(m_string);
  } else if(character == 9) {
    // Do nothing
    // Tab character catched.
  } else {
    m_string.insert(m_cursorPos, character);
    sf::Text* text = new sf::Text();
    if(m_maskingString != "")
      text->setString(m_maskingString);
    else
      text->setString(character);
    FontStyleUtils::setStyle(text, m_style);
    text->setColor(m_color);
    text->setCharacterSize(m_characterSize);
    text->setStyle(m_fontStyle);
    text->setFont(Config::getFontManager()->get(m_fontPath));
    m_letters.insert(m_letters.begin() + m_cursorPos, text);
    m_cursorPos++;
  }
}
void
LineEdit::applyStyle() {
  for(auto& it : m_letters) {
    FontStyleUtils::setStyle(it, m_style);
    it->setColor(m_color);
    it->setCharacterSize(m_characterSize);
    it->setStyle(m_fontStyle);
    it->setFont(Config::getFontManager()->get(m_fontPath));
  }
}
void
LineEdit::setFontStyle(sf::Text::Style style) {
  m_fontStyle = style;
  this->applyStyle();
}
void
LineEdit::setStyle(FontStyle style) {
  m_style = style;
  m_fontStyle = sf::Text::Style::Regular;
  m_characterSize = Config::getInt("DEFAULT_FONT_SIZE");
  m_color = Config::getColor("DEFAULT_FONT_COLOR");
  m_fontPath = Config::getString("DEFAULT_FONT");
  this->applyStyle();
}
void
LineEdit::setCharacterSize(unsigned int size) {
  m_characterSize = size;
  this->applyStyle();
}
void
LineEdit::setColor(const sf::Color& color) {
  m_color = color;
  this->applyStyle();
}
void
LineEdit::setMaskingString(const sf::String& mask) {
  m_maskingString = mask;
}
const sf::String&
LineEdit::getString() {
  return m_string;
}
FontStyle
LineEdit::getStyle() {
  return m_style;
}
sf::Text::Style
LineEdit::getFontStyle() {
  return m_fontStyle;
}
unsigned int
LineEdit::getCharacterSize() {
  return m_characterSize;
}
const sf::Color&
LineEdit::getColor() {
  return m_color;
}
Nano::signal<void(const sf::String&)>&
LineEdit::onFinished() {
  return m_onFinished;
}
Nano::signal<void(const sf::String&)>&
LineEdit::onChanged() {
  return m_onChanged;
}
bool
LineEdit::isFinished() {
  return m_isFinished;
}
bool
LineEdit::hasChanged() {
  return m_hasChanged;
}
const sf::String&
LineEdit::getMaskingString() {
  return m_maskingString;
}
Frame*
LineEdit::getFrame() {
  return m_frame;
}
}
