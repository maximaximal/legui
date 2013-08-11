#include <legui/LineEdit.h>
#include <legui/Config.h>
#include <legui/FontManagerAbstract.h>

namespace legui
{
    LineEdit::LineEdit(Container *parent)
        : Clickable(parent)
    {
        m_cursor = new Cursor();
        m_style = FontStyle::Regular;
        m_fontStyle = sf::Text::Style::Regular;
        m_characterSize = Config::getInt("DEFAULT_FONT_SIZE");
        m_color = Config::getColor("DEFAULT_FONT_COLOR");
        m_fontPath = Config::getString("DEFAULT_FONT");
        m_cursorPos = 0;
    }
    LineEdit::~LineEdit()
    {
        clear();
        delete m_cursor;
    }
    void LineEdit::clear()
    {
        for(auto &it : m_letters)
        {
            delete it;
        }
        m_letters.clear();
        m_string = "";
        m_cursorPos = 0;
        updateCursorPos();
    }

    void LineEdit::onUpdate(float frametime)
    {
        Clickable::onUpdate(frametime);
        m_cursor->onUpdate(frametime);
    }
    bool LineEdit::onEvent(const sf::Event &e)
    {
        bool block = Clickable::onEvent(e);
        if(!block)
        {
            m_cursor->onEvent(e);
            if(e.type == sf::Event::KeyPressed)
            {
                if(e.key.code == sf::Keyboard::Left)
                {
                    if(m_cursorPos > 0)
                        m_cursorPos -= 1;
                    updateCursorPos();
                }
                if(e.key.code == sf::Keyboard::Right)
                {
                    if(m_cursorPos < m_string.getSize())
                        m_cursorPos += 1;
                    updateCursorPos();
                }
            }
        }
        return block;
    }
    void LineEdit::setBoundingBox(const sf::FloatRect &box)
    {
        Clickable::setBoundingBox(box);
    }
    void LineEdit::updateSize()
    {
        Clickable::updateSize();
    
    }
    void LineEdit::D_onClicked(const sf::Vector2f &relPos)
    {
        float x = 0;
        for(std::size_t i = 0; relPos.x > x; ++i)
        {
            x += m_letters[i]->getGlobalBounds().width;
        }
        m_cursor->setBoundingBox(sf::FloatRect(x + m_boundingBox.left, m_boundingBox.top, m_characterSize, 2));
    }
    void LineEdit::updateCursorPos()
    {
        float x = 0;
        for(std::size_t i = 0; i < m_cursorPos; ++i)
        {
            x += m_letters[i]->getGlobalBounds().width;
        }
        m_cursor->setBoundingBox(sf::FloatRect(x + m_boundingBox.left, m_boundingBox.top, m_characterSize, 2));
    }
    void LineEdit::setString(const sf::String &text)
    {
        clear();
        for(std::size_t i = 0; i < text.getSize(); ++i)
        {
            this->appendCharacter(text[i]);
        }
    }
    void LineEdit::appendCharacter(sf::Uint32 character)
    {
        m_string.insert(m_string.getSize() - 1, character);
        sf::Text *text = new sf::Text();
        text->setString(character);
        m_letters.push_back(text);
    }
    void LineEdit::applyStyle()
    {
        for(auto &it : m_letters)
        {
            FontStyleUtils::setStyle(it, m_style);
            it->setColor(m_color);
            it->setCharacterSize(m_characterSize);
            it->setStyle(m_fontStyle);
            it->setFont(Config::getFontManager()->get(m_fontPath));
        }
    }
    void LineEdit::setFontStyle(sf::Text::Style style)
    {
        m_fontStyle = style;
    }
    void LineEdit::setStyle(FontStyle style)
    {
        m_style = style;
        m_fontStyle = sf::Text::Style::Regular;
        m_characterSize = Config::getInt("DEFAULT_FONT_SIZE");
        m_color = Config::getColor("DEFAULT_FONT_COLOR");
        m_fontPath = Config::getString("DEFAULT_FONT");
    }
    void LineEdit::setCharacterSize(unsigned int size)
    {
        m_characterSize = size;
    }
    void LineEdit::setColor(const sf::Color &color)
    {
        m_color = color;
    }
    const sf::String& LineEdit::getString()
    {
        return m_string;
    }
    FontStyle LineEdit::getStyle()
    {
        return m_style;
    }
    sf::Text::Style LineEdit::getFontStyle()
    {
        return m_fontStyle;
    }
    unsigned int LineEdit::getCharacterSize()
    {
        return m_characterSize;
    }
    const sf::Color& LineEdit::getColor()
    {
        return m_color;
    }
}
