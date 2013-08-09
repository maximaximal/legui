#pragma once

#include <string>
#include <legui/FontManagerAbstract.h>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Font.hpp>

namespace legui
{
    /**
     * @brief Default implementation of the font manager.
     */
    class FontManager : public FontManagerAbstract
    {
        public:
            FontManager();
            ~FontManager();

            virtual sf::Font& get(const std::string &filename);
            virtual void clear();
            virtual void free(const std::string &filename);
        private:
            std::map<std::string, sf::Font *> m_fonts;
    };
}
