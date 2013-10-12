#include <legui/Notification.h>
#include <legui/Config.h>

namespace legui
{
    Notification::Notification(Container *parent)
        : Clickable(parent)
    {
        m_closeIcon = 0;
        m_closeShape = 0;

        m_icon = new sf::Sprite();

        if(Config::getBool("USE_TEXTURES"))
            m_closeIcon = new sf::Sprite();
        else
            m_closeShape = new sf::RectangleShape();

        m_closeRect.width = 16;
        m_closeRect.height = 16;
    }
    Notification::~Notification()
    {
        delete m_icon;
        if(m_closeShape != 0)
            delete m_closeShape;
        if(m_closeIcon != 0)
            delete m_closeIcon;
    }

    void Notification::onUpdate(float frametime)
    {
    
    }
    bool Notification::onEvent(const sf::Event &e)
    {
        if(e.type == sf::Event::MouseMoved)
        {
            if(m_closeRect.contains(e.mouseMove.x, e.mouseMove.y))
            {
                //The close button has been hovered.

                this->close();
            }
        }

        //Don't block any other events!
        return false;
    }
    void Notification::setBoundingBox(const sf::FloatRect &box)
    {
        m_icon->setPosition(box.left, box.top + box.width / 2 - m_icon->getGlobalBounds().height / 2);
        m_closeRect.left = box.left + box.width - 32;
        m_closeRect.top = box.top + box.height - 32;
    }
    void Notification::updateSize()
    {
    
    }

    void Notification::fromNotificationData(const NotificationData &data)
    {
    
    }
    void Notification::D_onClicked(const sf::Vector2f &relPos)
    {
        if(m_closeRect.contains(relPos.x + m_boundingBox.left, relPos.y + m_boundingBox.top))
        {
            //The close button has been pressed.

            this->close();
        }
    
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
