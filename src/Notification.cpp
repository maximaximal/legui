#include <legui/Notification.h>

namespace legui
{
    Notification::Notification(Container *parent)
        : Clickable(parent)
    {
        m_icon = new sf::Sprite();
        m_closeIcon = new sf::Sprite();
    }
    Notification::~Notification()
    {
        delete m_icon;
        delete m_closeIcon;
    }

    void Notification::onUpdate(float frametime)
    {
    
    }
    void Notification::setBoundingBox(const sf::FloatRect &box)
    {
        m_icon->setPosition(box.left, box.top + box.width / 2 - m_icon->getGlobalBounds().height / 2);
    }
    void Notification::updateSize()
    {
    
    }

    void Notification::fromNotificationData(const NotificationData &data)
    {
    
    }
    void Notification::D_onClicked(const sf::Vector2f &relPos)
    {
    
    }
    bool Notification::onClose()
    {
        return m_close;
    }
    void Notification::close()
    {
        m_close = true;
    }
}
