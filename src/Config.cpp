#include <legui/Config.h>
#include <legui/FontManager.h>
using namespace std;

namespace legui
{
    Config::Config()
    {
        //Initialize the default font manager
            m_fontManager = new FontManager();
    }
    Config::~Config()
    {
        if(m_fontManager != 0)
            delete m_fontManager;
    }
    void Config::loadDefaults()
    {
        //Default Floats
            m_floats["STANDARD_HEIGHT"] = 20;
            m_floats["FRAME_OUTLINE_THICKNESS"] = 0;
        
        //Scrollbar
            m_floats["SCROLLBAR_WIDTH"] = 8;
            m_floats["SCROLLBAR_MIN_LENGHT"] = 100;
            m_bools["SCROLLBAR_HAS_MIDDLE_LINES"] = true;
            m_colors["SCROLLBAR_MIDDLE_LINES_COLOR"] = sf::Color(40, 40, 40);
        //Label
            m_ints["DEFAULT_FONT_SIZE"] = 14;
            m_colors["DEFAULT_FONT_COLOR"] = sf::Color(233, 233, 233);
            m_strings["DEFAULT_FONT"] = "Data/Fonts/DroidSans.ttf";
            m_bools["LABEL_PIXELPERFECT_POSITION"] = true;
            m_bools["LABEL_RECT_BORDER"] = false;
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
    void Config::setFontManager(FontManagerAbstract *fontManager)
    {
        if(m_fontManager != 0)
        {
            delete m_fontManager;
        }
        m_fontManager = fontManager;
    }
    FontManagerAbstract* Config::getFontManager()
    {
        return m_fontManager;
    }
}
