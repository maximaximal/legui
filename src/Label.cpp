#include <legui/Label.h>
#include <legui/Config.h>
#include <legui/FontManagerAbstract.h>

namespace legui
{
    Label::Label(Container *parent, const sf::String &text, Label::Style style)
        : Widget(parent)
    {
        m_text = new sf::Text();

        this->setStyle(style);
    }
    Label::~Label()
    {
        delete m_text;
    }

    void Label::setStyle(Label::Style style)
    {
        m_text->setFont(legui::Config::getFontManager()->get(Config::getString("DEFAULT_FONT")));
        unsigned int defaultSize = Config::getInt("DEFAULT_FONT_SIZE");
        m_text->setCharacterSize(defaultSize);
        m_text->setColor(Config::getColor("DEFAULT_FONT_COLOR"));

        switch(style)
        {
            case Style::Regular:
                break;
            case Style::Heading1:
                m_text->setCharacterSize(defaultSize * 2);
                break;
            case Style::Heading2:
                m_text->setCharacterSize(defaultSize * 1.5);
                break;
            case Style::Heading3:
                m_text->setCharacterSize(defaultSize * 1.17);
                break;
            case Style::Heading4:
                m_text->setCharacterSize(defaultSize);
                break;
            case Style::Heading5:
                m_text->setCharacterSize(defaultSize * 0.83);
                break;
            case Style::Heading6:
                m_text->setCharacterSize(defaultSize * 0.75);
                break;
        };
        m_style = style;
        this->updateSize();
    }
    void Label::setBoundingBox(const sf::FloatRect &box)
    {
        Widget::setBoundingBox(box);

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
            for(std::size_t i = 0; i < m_text->getString().getSize(); ++i)
            {
                sf::String currentlyVisible("");
                if(m_text->findCharacterPos(i).x > m_boundingBox.left + m_boundingBox.width)
                {
                    m_text->setString(currentlyVisible);
                    continue;
                }
                currentlyVisible += m_text->getString()[i];
            }
        }
        else
        {
            m_boundingBox.width = m_text->getGlobalBounds().width;
            m_boundingBox.height = m_text->getGlobalBounds().height;
        }
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
    Label::Style Label::getStyle()
    {
        return m_style;
    }
    unsigned int Label::getCharacterSize()
    {
        return m_text->getCharacterSize();
    }
}
