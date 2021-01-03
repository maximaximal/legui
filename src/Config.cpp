#include <iostream>
#include <legui/Config.h>
#include <legui/FontManager.h>
#include <legui/TextureManagerAbstract.h>

using namespace std;

namespace legui {
// Define the private maps
std::map<std::string, std::string> Config::m_strings =
  std::map<std::string, std::string>();
std::map<std::string, int> Config::m_ints = std::map<std::string, int>();
std::map<std::string, float> Config::m_floats = std::map<std::string, float>();
std::map<std::string, bool> Config::m_bools = std::map<std::string, bool>();
std::map<std::string, sf::Color> Config::m_colors =
  std::map<std::string, sf::Color>();
// Define the font manager
FontManagerAbstract* Config::m_fontManager = new FontManager();
// Define the texture manager
TextureManagerAbstract* Config::m_textureManager = 0;

Config::Config() {}
Config::~Config() {
  if(m_fontManager != 0)
    delete m_fontManager;
  if(m_textureManager != 0)
    delete m_textureManager;
}
void
Config::loadDefaults() {
  // Default Floats
  Config::m_floats["STANDARD_HEIGHT"] = 20;
  Config::m_floats["FRAME_OUTLINE_THICKNESS"] = 0;
  // Cursor
  Config::m_floats["CURSOR_WIDTH"] = 2;
  Config::m_floats["CURSOR_BLINK_RATE"] = 0.53;
  Config::m_colors["CURSOR_ACTIVE"] = sf::Color::White;
  Config::m_colors["CURSOR_UNACTIVE"] = sf::Color::Transparent;
  // Progress Bar
  Config::m_floats["PROGRESSBAR_OUTLINE_THICKNESS"] = 3;
  Config::m_colors["PROGRESSBAR_OUTLINE_COLOR"] = sf::Color(0, 2, 100);
  Config::m_colors["PROGRESSBAR_FILL_COLOR_LEFT"] = sf::Color(3, 32, 255);
  Config::m_colors["PROGRESSBAR_FILL_COLOR_RIGHT"] = sf::Color(0, 10, 87);
  // Push Button
  Config::m_colors["BUTTON_OUTLINE_FOCUSED"] = sf::Color(62, 79, 156, 190);
  Config::m_colors["BUTTON_OUTLINE"] = sf::Color(62, 79, 156, 20);
  Config::m_colors["BUTTON_FILL_HOVER"] = sf::Color(0, 26, 104);
  Config::m_colors["BUTTON_FILL"] = sf::Color(0, 38, 59);
  Config::m_floats["BUTTON_OUTLINE_THICKNESS"] = 3;
  // Scrollbar
  Config::m_floats["SCROLLBAR_WIDTH"] = 8;
  Config::m_floats["SCROLLBAR_MIN_LENGHT"] = 100;
  Config::m_bools["SCROLLBAR_HAS_MIDDLE_LINES"] = true;
  Config::m_colors["SCROLLBAR_MIDDLE_LINES_COLOR"] = sf::Color(40, 40, 40);
  // Label
  Config::m_ints["DEFAULT_FONT_SIZE"] = 14;
  Config::m_colors["DEFAULT_FONT_COLOR"] = sf::Color(233, 233, 233);
  Config::m_strings["DEFAULT_FONT"] = "Data/Fonts/DroidSans.ttf";
  Config::m_bools["LABEL_PIXELPERFECT_POSITION"] = true;
  Config::m_bools["LABEL_RECT_BORDER"] = false;
  // Default Colors
  Config::m_colors["FRAME_OUTLINE_COLOR"] =
    sf::Color(120, 120, 120);// Darker Grey
  Config::m_colors["FRAME_FILL_COLOR"] =
    sf::Color(255, 255, 255, 0);// Transparent
  // Notifications
  Config::m_colors["NOTIFICATION_CLOSE_FILL_HOVER"] = sf::Color(100, 100, 100);
  Config::m_colors["NOTIFICATION_CLOSE_OUTLINE_HOVER"] = sf::Color(40, 40, 40);
  Config::m_colors["NOTIFICATION_CLOSE_FILL"] = sf::Color(150, 150, 150);
  Config::m_colors["NOTIFICATION_CLOSE_OUTLINE"] = sf::Color(80, 80, 80);
  Config::m_strings["NOTIFICATION_CLOSE_ICONTEX_RECT"] = "NotificationClose";
  Config::m_strings["NOTIFICATION_CLOSE_ICONTEX_RECT_HOVER"] =
    "NotificationCloseHover";
  Config::m_strings["NOTIFICATION_CLOSE_ICONTEX"] = "Data/Textures/LeGUI.xml";
  Config::m_ints["NOTIFICATIONLIST_MARGIN"] = 10;
  // TextureManager
  Config::m_bools["USE_TEXTURES"] = false;
}
std::string
Config::getString(const std::string& ID) {
  if(Config::m_strings.count(ID) > 0)
    return Config::m_strings[ID];
  else
    cout << "[LEGUI] Config-String \"" << ID << "\" not found!" << endl;
}
int
Config::getInt(const std::string& ID) {
  if(Config::m_ints.count(ID) > 0)
    return Config::m_ints[ID];
  else
    cout << "[LEGUI] Config-Int \"" << ID << "\" not found!" << endl;
}
float
Config::getFloat(const std::string& ID) {
  if(Config::m_floats.count(ID) > 0)
    return Config::m_floats[ID];
  else
    cout << "[LEGUI] Config-Float \"" << ID << "\" not found!" << endl;
}
bool
Config::getBool(const std::string& ID) {
  if(Config::m_bools.count(ID) > 0)
    return Config::m_bools[ID];
  else
    cout << "[LEGUI] Config-Bool \"" << ID << "\" not found!" << endl;
}
sf::Color&
Config::getColor(const std::string& ID) {
  if(Config::m_colors.count(ID) > 0)
    return Config::m_colors[ID];
  else
    cout << "[LEGUI] Config-Color \"" << ID << "\" not found!" << endl;
}

void
Config::setString(const std::string& ID, const std::string& value) {
  Config::m_strings[ID] = value;
}
void
Config::setInt(const std::string& ID, int value) {
  Config::m_ints[ID] = value;
}
void
Config::setBool(const std::string& ID, bool value) {
  Config::m_bools[ID] = value;
}
void
Config::setFloat(const std::string& ID, float value) {
  Config::m_floats[ID] = value;
}
void
Config::setColor(const std::string& ID, const sf::Color& value) {
  Config::m_colors[ID] = value;
}
void
Config::setFontManager(FontManagerAbstract* fontManager) {
  if(Config::m_fontManager != 0) {
    delete Config::m_fontManager;
  }
  Config::m_fontManager = fontManager;
}
void
Config::setTextureManager(TextureManagerAbstract* textureManager) {
  if(Config::m_textureManager != 0) {
    delete Config::m_textureManager;
  }
  Config::m_textureManager = textureManager;
  Config::m_bools["USE_TEXTURES"] = true;
}
FontManagerAbstract*
Config::getFontManager() {
  return Config::m_fontManager;
}
TextureManagerAbstract*
Config::getTextureManager() {
  return Config::m_textureManager;
}
}
