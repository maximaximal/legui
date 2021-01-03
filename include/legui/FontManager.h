#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/System/String.hpp>
#include <legui/FontManagerAbstract.h>
#include <string>

namespace legui {
/**
 * @brief Default implementation of the font manager.
 */
class FontManager : public FontManagerAbstract {
  public:
  FontManager();
  ~FontManager();

  virtual sf::Font& get(const std::string& filename);
  virtual void clear();
  virtual void free(const std::string& filename);

  private:
  std::map<std::string, sf::Font*> m_fonts;
};
}
