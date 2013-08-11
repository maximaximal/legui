#include <legui/FontStyle.h>
#include <legui/Config.h>
#include <legui/FontManagerAbstract.h>

namespace legui
{
    void FontStyleUtils::setStyle(sf::Text *text, FontStyle style)
    {
        text->setFont(legui::Config::getFontManager()->get(Config::getString("DEFAULT_FONT")));
        unsigned int defaultSize = Config::getInt("DEFAULT_FONT_SIZE");
        text->setCharacterSize(defaultSize);
        text->setColor(Config::getColor("DEFAULT_FONT_COLOR"));

        switch(style)
        {
            case FontStyle::Regular:
                break;
            case FontStyle::Heading1:
                text->setCharacterSize(defaultSize * 2);
                break;
            case FontStyle::Heading2:
                text->setCharacterSize(defaultSize * 1.5);
                break;
            case FontStyle::Heading3:
                text->setCharacterSize(defaultSize * 1.17);
                break;
            case FontStyle::Heading4:
                text->setCharacterSize(defaultSize);
                break;
            case FontStyle::Heading5:
                text->setCharacterSize(defaultSize * 0.83);
                break;
            case FontStyle::Heading6:
                text->setCharacterSize(defaultSize * 0.75);
                break;
        };
    }
}
