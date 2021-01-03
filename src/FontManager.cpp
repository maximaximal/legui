#include <legui/FontManager.h>

namespace legui {
FontManager::FontManager() {}
FontManager::~FontManager() {
  clear();
}
void
FontManager::clear() {
  for(auto& it : m_fonts) {
    delete it.second;
  }
  m_fonts.clear();
}
void
FontManager::free(const std::string& filename) {
  delete m_fonts.at(filename);
  m_fonts.erase(filename);
}
sf::Font&
FontManager::get(const std::string& filename) {
  if(m_fonts.count(filename) == 0) {
    sf::Font* font = new sf::Font();
    font->loadFromFile(filename);
    m_fonts[filename] = font;
  }
  return *(m_fonts[filename]);
}
}
