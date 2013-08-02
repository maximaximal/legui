#include <legui/HorizontalSplitter.h>
#include <legui/Config.h>

namespace legui
{
    void HorizontalSplitter::setBoundingBox(const sf::FloatRect &box)
    {
        float offset = 0;
        for(std::size_t i = 0; i < getSize(); ++i)
        {
            if(i % 2 == 0)  //Number is even. (left side)
            {
                m_widgets[i]->setBoundingBox(sf::FloatRect(box.left, box.height + offset, box.width / 2, Config::getFloat("STANDARD_HEIGHT")));
            }
            else            //Number is not even. (right side)
            {
                m_widgets[i]->setBoundingBox(sf::FloatRect(box.left + box.width / 2, box.height + offset, box.width / 2, Config::getFloat("STANDARD_HEIGHT")));
                //Update the size of the widget.
                m_widgets[i]->updateSize();
                //Increase the y offset based on the height of the last right element.
                offset += m_widgets[i]->getBoundingBox().height;
            }
        }
    }
    void HorizontalSplitter::updateSize()
    {
        m_boundingBox.height = 0;
        for(auto &it : m_widgets)
        {
            it->updateSize();
            m_boundingBox.height += it->getBoundingBox().height;
        }
    }
}
