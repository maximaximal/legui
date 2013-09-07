#include <legui/NotificationData.h>

namespace legui
{
    NotificationData::NotificationData(const std::string &title, const std::string &description)
    {
        m_title = title;
        m_description = description;
        m_textureNumber = 0;
    }
    NotificationData::~NotificationData()
    {
    
    }

    void NotificationData::setTitle(const std::string &value)
    {
        m_title = value;
    }
    void NotificationData::setDescription(const std::string &value)
    {
        m_description = value;
    }
    void NotificationData::setIconTexture(const std::string &value)
    {
        m_texture = value;
    }
    void NotificationData::setIconTextureRect(const std::string &value)
    {
        m_textureRect = value;
    }
    void NotificationData::setIconTextureNumber(unsigned int number)
    {
        m_textureNumber;
    }

    const std::string& NotificationData::getTitle()
    {
        return m_title;
    }
    const std::string& NotificationData::getDescription()
    {
        return m_description;
    }
    const std::string& NotificationData::getIconTexture()
    {
        return m_texture;
    }
    const std::string& NotificationData::getIconTextureRect()
    {
        return m_textureRect;
    }
    unsigned int NotificationData::getIconTextureNumber()
    {
        return m_textureNumber;
    }
}
