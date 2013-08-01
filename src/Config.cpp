#include <legui/Config.h>

using namespace std;

namespace legui
{
    void Config::loadDefaults()
    {
        //Default Floats
            m_floats["STANDARD_HEIGHT"] = 20;
            m_floats["FRAME_OUTLINE_THICKNESS"] = 0;
        //Default Colors
            m_colors["FRAME_OUTLINE_COLOR"] = sf::Color(120, 120, 120); //Darker Grey
            m_colors["FRAME_FILL_COLOR"] = sf::Color(255, 255, 255, 0); //Transparent
    }
    std::string Config::getString(const std::string &ID)
    {
        return m_strings[ID];
    }
    int Config::getInt(const std::string &ID)
    {
        return m_ints[ID];
    }
    float Config::getFloat(const std::string &ID)
    {
        return m_floats[ID];
    }
    bool Config::getBool(const std::string &ID)
    {
        return m_bools[ID];
    }
    sf::Color& Config::getColor(const std::string &ID)
    {
        return m_colors[ID];
    }
    
    void Config::setString(const std::string &ID, const std::string &value)
    {
        m_strings[ID] = value;
    }
    void Config::setInt(const std::string &ID, int value)
    {
        m_ints[ID] = value;
    }
    void Config::setBool(const std::string &ID, bool value)
    {
        m_bools[ID] = value;
    }
    void Config::setFloat(const std::string &ID, float value)
    {
        m_floats[ID] = value;
    }
    void Config::setColor(const std::string &ID, const sf::Color &value)
    {
        m_colors[ID] = value;
    }
}
