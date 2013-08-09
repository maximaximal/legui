#pragma once

#include <string>
#include <SFML/Graphics/Font.hpp>

namespace legui
{
    /**
     * @brief This is the abstract base class of the legui font manager.
     *
     * It is ment to be derived from your font manager to use the same ressources you use.
     */
    class FontManagerAbstract
    {
        public:
            /**
             * @brief Gets the required font from the internal storage & loads it if necessary. 
             *
             * @param filename The path to the font (origin in the working dir).
             *
             * @return A reference to the required font.
             */
            virtual sf::Font& get(const std::string &filename) = 0;
            /**
             * @brief Clears (deletes) all saved fonts. 
             *
             * Previously assigned fonts will no longer be there. If the objects using them aren't
             * deleted there will be a segmentation fault!.
             */
            virtual void clear() = 0;
            /**
             * @brief Frees the wanted font from memory.
             *
             * If a font was only used for a short time by only one user, it should
             * be freed after using it.
             *
             * @param filename The path to the font (ID).
             */
            virtual void free(const std::string &filename) = 0;
    };
}
