#include <legui/CenteredStrip.h>

namespace legui
{
    CenteredStrip::CenteredStrip(Container *parent)
        : Container(parent)
    {
        
    }
    CenteredStrip::~CenteredStrip()
    {
    
    }
    void CenteredStrip::setBoundingBox(const sf::FloatRect &box)
    {
        sf::FloatRect middle;
        float y = 0;
        for(auto &it : m_widgets)
        {
            middle = it->getBoundingBox();
            middle.left = box.left + box.width / 2 - middle.width / 2;
            middle.top = y;
            it->setBoundingBox(middle);
            y += middle.height;
        }
    }
}
