#include <legui/NotificationData.h>

namespace legui
{
    NotificationData::NotificationData(const std::string &title, const std::string &description)
    {
    
    }
    NotificationData::~NotificationData()
    {
        
    }

    void NotificationData::setTitle(const std::string &title)
    {
        m_title = title;
    }
    void NotificationData::setDescription(const std::string &description)
    {
        m_description = description;
    }
    void NotificationData::setIconTexture(const std::string &iconTexture)
    {
        m_texture = iconTexture;
    }
    void NotificationData::setIconTextureRect(const std::string &iconTextureRect)
    {
        m_textureRect = iconTextureRect;
    }
    void NotificationData::setIconTextureNumber(unsigned int iconTextureNumber)
    {
        m_textureNumber = iconTextureNumber;
    }
    
    const std::string &NotificationData::getTitle()
    {
        return m_title;
    }
    const std::string &NotificationData::getDescription()
    {
        return m_description;
    }
    const std::string &NotificationData::getIconTexture()
    {
        return m_texture;
    }
    const std::string &NotificationData::getIconTextureRect()
    {
        return m_textureRect;
    }
    unsigned int NotificationData::getIconTextureNumber()
    {
        return m_textureNumber;
    }
}
