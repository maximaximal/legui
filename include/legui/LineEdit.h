#pragma once

#include <vector>
#include <string>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>
#include <legui/Clickable.h>
#include <legui/Frame.h>
#include <legui/FontStyle.h>
#include <legui/Cursor.h>

namespace legui
{
    /**
     * @brief A editable line for simple edit tasks.
     */
    class LineEdit : public Clickable
    {
        public:
            LineEdit(Container* parent = 0);
            virtual ~LineEdit();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();

            /**
             * @brief Clears the input field.
             */
            void clear();
            /**
             * @brief Sets a string.
             *
             * @param text The string to be set.
             */
            void setString(const sf::String &text);
            /**
             * @brief Appends a character to the graphical output & the internal string.
             *
             * @param character
             */
            void appendCharacter(sf::Uint32 character);
            /**
             * @brief Applies the style set to the text.
             *
             * This function is automatically called when you set a style, 
             * you shouldn't have to call this by yourself.
             */
            void applyStyle();
            /**
             * @brief Apply a SFML text style to the text.
             *
             * This style will override the predefined style. 
             *
             * @param style The style to be applied.
             */
            void setFontStyle(sf::Text::Style style);
            /**
             * @brief Apply a predefined style to the text.
             *
             * This will override all other styles applied to the text (character size,
             * color, ...). These options have to be set individually.
             *
             * @param style The style to be applied.
             */
            void setStyle(FontStyle style);
            /**
             * @brief Sets the character size of the text.
             *
             * This will override the character size from the predefined style.
             *
             * @param size The character size.
             */
            void setCharacterSize(unsigned int size);
            /**
             * @brief Sets the color of the text.
             *
             * This will override the color from the predefined style.
             *
             * @param color The color.
             */
            void setColor(const sf::Color &color);
            /**
             * @brief Sets the font of the text.
             *
             * @param fontPath The path to the font (working directory).
             */
            void setFont(std::string fontPath);
            /**
             * @brief Updates the positions of the leters.
             */
            void updateLetterPos();
            /**
             * @brief Returns the currently string in the edit.
             *
             * @return The current string.
             */
            const sf::String& getString();
            /**
             * @brief Returns the font path.
             *
             * @return The path to the font applied.
             */
            std::string getFontPath();
            /**
             * @brief Returns the predefined style of the text.
             *
             * @return The predefined style.
             */
            FontStyle getStyle();
            /**
             * @brief Returns the sf::Text style of the text.
             *
             * @return The sf::Text style.
             */
            sf::Text::Style getFontStyle();
            /**
             * @brief Returns the character size of the text.
             *
             * @return The character size.
             */
            unsigned int getCharacterSize();
            /**
             * @brief Returns the color of the text.
             *
             * @return The color.
             */
            const sf::Color& getColor();

            /**
             * @brief Returns the internal background frame.
             */
            Frame* getFrame();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        
            virtual void D_onClicked(const sf::Vector2f &relPos);
        private:
            /**
             * @brief Updates the cursor. (only needed interbnally)
             */
            void updateCursorPos();
            /**
             * @brief Holds all the letters of the widget.
             */
            std::vector<sf::Text*> m_letters;
            std::string m_fontPath;
            unsigned int m_characterSize;
            std::size_t m_cursorPos;
            Frame *m_frame;
            sf::Text::Style m_fontStyle;
            FontStyle m_style;
            sf::String m_string;
            sf::Color m_color;
            Cursor *m_cursor;
            float m_xOffset;
    };
}
