#pragma once

#include <legui/Widget.h>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>

namespace legui
{
    /**
     * @brief Represents a static line of text.
     */
    class Label : public Widget
    {
        public:
            enum Style {
                Regular,
                Heading1,
                Heading2,
                Heading3,
                Heading4,
                Heading5,
                Heading6
            };
            Label(Container *parent = 0, const sf::String &text = "", Label::Style style = Label::Style::Regular);
            virtual ~Label();
            
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();

            virtual void setString(const sf::String &text);
            virtual void setFont(const sf::Font &font);
            virtual void setFontStyle(sf::Text::Style style);
            virtual void setStyle(Label::Style style);
            virtual void setCharacterSize(unsigned int size);
            const sf::String& getString(); 
            const sf::String& getVisibleString(); 
            const sf::Font* getFont();
            sf::Text::Style getFontStyle();
            Label::Style getStyle();
            unsigned int getCharacterSize();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            sf::Text *m_text;
            sf::String m_string;
            Label::Style m_style;
    };
}
