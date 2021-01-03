#pragma once

#include <SFML/Graphics/Color.hpp>
#include <map>
#include <string>

namespace legui {
class FontManagerAbstract;
class TextureManagerAbstract;

/**
 * @brief Saves the GUI configuration.
 *
 * This configuration is used by every configurable LeGUI element.
 */
class Config {
  public:
  /**
   * @brief Loads the default, hardcoded values in the config.
   */
  static void loadDefaults();

  static std::string getString(const std::string& ID);
  static int getInt(const std::string& ID);
  static bool getBool(const std::string& ID);
  static float getFloat(const std::string& ID);
  static sf::Color& getColor(const std::string& ID);

  static void setString(const std::string& ID, const std::string& value);
  static void setInt(const std::string& ID, int value);
  static void setFloat(const std::string& ID, float value);
  static void setBool(const std::string& ID, bool value);
  static void setColor(const std::string& ID, const sf::Color& value);

  static void setFontManager(FontManagerAbstract* fontManager);
  /**
   * @brief Sets a texture manager to be used.
   *
   * When a manager is set, all newly created elements which need a texture will
   * load it through this manager.
   *
   * If no manager is set, no textures will be loaded and legui will only
   * use simple shapes to display it's widgets.
   *
   * @param textureManager The manager to use.
   */
  static void setTextureManager(TextureManagerAbstract* textureManager);
  static FontManagerAbstract* getFontManager();
  static TextureManagerAbstract* getTextureManager();

  private:
  Config();
  ~Config();

  static std::map<std::string, std::string> m_strings;
  static std::map<std::string, int> m_ints;
  static std::map<std::string, float> m_floats;
  static std::map<std::string, bool> m_bools;
  static std::map<std::string, sf::Color> m_colors;

  static FontManagerAbstract* m_fontManager;
  static TextureManagerAbstract* m_textureManager;
};
}
