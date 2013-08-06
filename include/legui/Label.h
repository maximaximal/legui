#pragma once

#include <legui/Widget.h>
#include <SFML/Graphics/Text.hpp>

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
            Label(Container *parent = 0, const sf::String &text = "", label::Style style = Label::Style::Regular);
            virtual ~Label();
            
            virtual void setString(const sf::String &text);
            virtual void setFont(const sf::Font &font);
            virtual void setFontStyle(sf::Text::Style style);
            virtual void setStyle(Label::Style style);
            const sf::String& getString(); 
            const sf::Font& getFont();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            sf::Text *m_text;
            label::Style m_style;
    };
}
