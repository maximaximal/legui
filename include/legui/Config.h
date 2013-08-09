#pragma once

#include <string>
#include <map>
#include <SFML/Graphics/Color.hpp>

namespace legui
{
    class FontManagerAbstract;

    /**
     * @brief Saves the GUI configuration.
     *
     * This configuration is used by every configurable LeGUI element.
     */
    class Config
    {
        public:
            /**
             * @brief Loads the default, hardcoded values in the config.
             */
            static void loadDefaults();
            
            static std::string getString(const std::string &ID);
            static int getInt(const std::string &ID);
            static bool getBool(const std::string &ID);
            static float getFloat(const std::string &ID);
            static sf::Color& getColor(const std::string &ID);
        
            static void setString(const std::string &ID, const std::string &value);
            static void setInt(const std::string &ID, int value);
            static void setFloat(const std::string &ID, float value);
            static void setBool(const std::string &ID, bool value);
            static void setColor(const std::string &ID, const sf::Color &value);

            static void setFontManager(FontManagerAbstract *fontManager);
            static FontManagerAbstract* getFontManager();
        private:
            Config();
            ~Config();

            static std::map<std::string, std::string> m_strings;
            static std::map<std::string, int> m_ints;
            static std::map<std::string, float> m_floats;
            static std::map<std::string, bool> m_bools;
            static std::map<std::string, sf::Color> m_colors;

            static FontManagerAbstract *m_fontManager;
    };
}
