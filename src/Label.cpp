#include <legui/Label.h>
#include <legui/Config.h>
#include <legui/FontManagerAbstract.h>

namespace legui
{
    Label::Label(Container *parent, const sf::String &text, FontStyle style)
        : Widget(parent)
    {
        m_text = new sf::Text();
        this->setString(text);
        this->setStyle(style);
    }
    Label::~Label()
    {
        delete m_text;
    }

    void Label::setStyle(FontStyle style)
    {
        FontStyleUtils::setStyle(m_text, style);
        this->updateSize();
    }
    void Label::setBoundingBox(const sf::FloatRect &box)
    {
        Widget::setBoundingBox(box);
        this->setCharacterSize((unsigned int) box.height);

        if(Config::getBool("LABEL_PIXELPERFECT_POSITION"))
            m_text->setPosition(sf::Vector2f((int) box.left, (int) box.top));
        else
            m_text->setPosition(sf::Vector2f(box.left, box.top));
    }
    void Label::updateSize()
    {
        Widget::updateSize();

        if(Config::getBool("LABEL_RECT_BORDER"))
        {
            sf::String currentlyVisible("");
            for(std::size_t i = 0; i < m_text->getString().getSize(); ++i)
            {
                if(m_text->findCharacterPos(i).x > m_boundingBox.left + m_boundingBox.width)
                {
                    m_text->setString(currentlyVisible);
                    continue;
                }
                currentlyVisible += m_text->getString()[i];
            }
            m_text->setString(currentlyVisible);
        }
        m_boundingBox.width = m_text->getGlobalBounds().width;
        m_boundingBox.height = m_text->getGlobalBounds().height;
    }
    void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_text, states);
    }
    void Label::setCharacterSize(unsigned int size)
    {
        m_text->setCharacterSize(size);
        this->updateSize();
    }
    void Label::setFont(const sf::Font &font)
    {
        m_text->setFont(font);
        this->updateSize();
    }
    void Label::setString(const sf::String &text)
    {
        m_text->setString(text);
        m_string = text;
        this->updateSize();
    }
    void Label::setFontStyle(sf::Text::Style style)
    {
        m_text->setStyle(style);
        this->updateSize();
    }
    void Label::setOrigin(const sf::Vector2f &origin)
    {
        m_text->setOrigin(origin);
    }
    const sf::String& Label::getVisibleString()
    {
        return m_text->getString();
    }
    const sf::String& Label::getString()
    {
        return m_string;
    }
    const sf::Font* Label::getFont()
    {
        return m_text->getFont();
    }
    sf::Text::Style Label::getFontStyle()
    {
        return static_cast<sf::Text::Style>(m_text->getStyle());
    }
    FontStyle Label::getStyle()
    {
        return m_style;
    }
    unsigned int Label::getCharacterSize()
    {
        return m_text->getCharacterSize();
    }
    sf::Vector2f Label::getSize()
    {
        return sf::Vector2f(m_text->getLocalBounds().width, m_text->getLocalBounds().height);
    }
}
