#include <legui/Config.h>
#include <legui/FontManager.h>
using namespace std;

namespace legui
{
    //Define the private maps
        std::map<std::string, std::string> Config::m_strings = std::map<std::string, std::string>();
        std::map<std::string, int> Config::m_ints = std::map<std::string, int>();
        std::map<std::string, float> Config::m_floats = std::map<std::string, float>();
        std::map<std::string, bool> Config::m_bools = std::map<std::string, bool>();
        std::map<std::string, sf::Color> Config::m_colors = std::map<std::string, sf::Color>();
    //Define the font manager
        FontManagerAbstract* Config::m_fontManager = new FontManager();
    
    Config::Config()
    {

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
        //Cursor
            m_floats["CURSOR_WIDTH"] = 2;
            m_floats["CUROSR_BLINK_RATE"] = 0.53;
            m_colors["CURSOR_ACTIVE"] = sf::Color::White;
            m_colors["CURSOR_UNACTIVE"] = sf::Color::Transparent;
        //Push Button
            m_colors["BUTTON_OUTLINE_FOCUSED"] = sf::Color(62, 79, 156, 190);
            m_colors["BUTTON_OUTLINE"] = sf::Color(62, 79, 156, 20);
            m_colors["BUTTON_FILL_HOVER"] = sf::Color(128, 128, 128);
            m_colors["BUTTON_FILL"] = sf::Color(186, 186, 186);
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
