#include <legui/HorizontalSplitter.h>
#include <legui/Config.h>

namespace legui
{
    HorizontalSplitter::HorizontalSplitter(Container *parent)
        : Container(parent)
    {
        m_padding = 0;
    }
    void HorizontalSplitter::setBoundingBox(const sf::FloatRect &box)
    {
        Container::setBoundingBox(box);
        float offset = 0;
        for(std::size_t i = 0; i < getSize(); ++i)
        {
            if(i % 2 == 0)  //Number is even. (left side)
            {
                m_widgets[i]->updateSize();
                m_widgets[i]->setBoundingBox(sf::FloatRect(box.left, box.top + offset, box.width / 2 - m_padding / 2, m_widgets[i]->getBoundingBox().height));
            }
            else            //Number is not even. (right side)
            {
                //Update the size of the widget.
                m_widgets[i]->updateSize();
                m_widgets[i]->setBoundingBox(sf::FloatRect(box.left + box.width / 2 + m_padding / 2, box.top + offset, box.width / 2 - m_padding / 2, m_widgets[i]->getBoundingBox().height));
                //Increase the y offset based on the height of the last right element.
                offset += m_widgets[i]->getBoundingBox().height;
            }
        }
        m_boundingBox.height = offset;
    }
    void HorizontalSplitter::updateSize()
    {
        m_boundingBox.height = 0;
        for(std::size_t i = 0; i < getSize(); ++i)
        {
            if(i % 2 != 0)  //Number is not even. (right side)
            {
                m_widgets[i]->updateSize();
                m_boundingBox.height += m_widgets[i]->getBoundingBox().height;
            }
        }
    }
    void HorizontalSplitter::setPadding(float padding)
    {
        m_padding = padding;
    }
    float HorizontalSplitter::getPadding()
    {
        return m_padding;
    }
}
