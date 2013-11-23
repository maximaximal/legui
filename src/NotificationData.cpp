#include <legui/NotificationData.h>

namespace legui
{
    NotificationData::NotificationData(const std::string &title, const std::string &description)
    {
        m_title = title;
        m_description = description;
    }
    NotificationData::NotificationData(const NotificationData &other)
    {
        m_title = other.getTitle();
        m_description = other.getDescription();
        m_texture = other.getIconTexture();
        m_textureRect = other.getIconTextureRect();
        m_textureNumber = other.getIconTextureNumber();
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
    
    const std::string &NotificationData::getTitle() const
    {
        return m_title;
    }
    const std::string &NotificationData::getDescription() const
    {
        return m_description;
    }
    const std::string &NotificationData::getIconTexture() const
    {
        return m_texture;
    }
    const std::string &NotificationData::getIconTextureRect() const
    {
        return m_textureRect;
    }
    unsigned int NotificationData::getIconTextureNumber() const
    {
        return m_textureNumber;
    }
}
