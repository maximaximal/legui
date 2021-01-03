#pragma once

namespace legui {
/**
 * @brief Describes the default texture manager class for legui.
 *
 * To use your own texture manager together with legui, register it in the
 * config and derive it from this class.
 */
class TextureManagerAbstract {
  public:
  /**
   * @brief Returns the texture with the given path.
   *
   * @param path The path (filesystem) to the texture.
   *
   * @return A reference to the texture.
   */
  virtual sf::Texture& get(const std::string& path) = 0;
  /**
   * @brief Returns the predefined rectangle of a texture.
   *
   * @param path The path to the texture.
   * @param rect The rectangle of the texture.
   * @param number The number of the texture.
   *
   * @return The defined rectangle.
   */
  virtual const sf::IntRect& getRect(const std::string& path,
                                     const std::string& rect,
                                     unsigned int number) = 0;
};
}
