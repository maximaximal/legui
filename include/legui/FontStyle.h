#pragma once

#include <SFML/Graphics/Text.hpp>

namespace legui
{
    /**
     * Pre-defined styles a font can have.
     */
    enum class FontStyle {
        Regular,
        Heading1,
        Heading2,
        Heading3,
        Heading4,
        Heading5,
        Heading6
    };
    /**
     * @brief Pre-defined font styles utility class.
     */
    class FontStyleUtils
    {
        public:
            /**
             * @brief Sets the style of an sf::Text to the desired FontStyle.
             *
             * @param text Pointer to the sf::Text object.
             * @param style The style to set.
             */
            static void setStyle(sf::Text *text, FontStyle style);
    };
}
