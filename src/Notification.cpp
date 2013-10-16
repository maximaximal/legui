#include <legui/Notification.h>
#include <legui/Config.h>
#include <legui/TextureManagerAbstract.h>
#include <legui/FontStyle.h>

namespace legui
{
    Notification::Notification(Container *parent)
        : Clickable(parent)
    {
        m_closeIcon = 0;
        m_closeShape = 0;

        m_icon = new sf::Sprite();

        if(Config::getBool("USE_TEXTURES"))
        {
            m_closeIcon = new sf::Sprite();
            m_closeIcon->setTextureRect(Config::getTextureManager()->getRect(Config::getString("NOTIFICATION_CLOSE_ICONTEX"),
                Config::getString("NOTIFICATION_CLOSE_ICONTEX_RECT"), 0));
        }           
        else
        {
            m_closeShape = new sf::RectangleShape();
            m_closeShape->setOutlineThickness(1);
            m_closeShape->setOutlineColor(Config::getColor("NOTIFICATION_CLOSE_OUTLINE"));
            m_closeShape->setFillColor(Config::getColor("NOTIFICATION_CLOSE_FILL"));
        }

        m_title = new legui::Label();
        m_description = new legui::Label();

        m_title->setStyle(FontStyle::Heading2);
        m_description->setStyle(FontStyle::Regular);

        m_closeRect.width = 16;
        m_closeRect.height = 16;
    }
    Notification::~Notification()
    {
        delete m_icon;
        delete m_title;
        delete m_description;
        if(m_closeShape != 0)
            delete m_closeShape;
        if(m_closeIcon != 0)
            delete m_closeIcon;
    }

    void Notification::onUpdate(float frametime)
    {
        Clickable::onUpdate(frametime);
    }
    bool Notification::onEvent(const sf::Event &e)
    {
        bool block = false;
        block = Clickable::onEvent(e);
        if(e.type == sf::Event::MouseMoved)
        {
            if(m_closeRect.contains(e.mouseMove.x, e.mouseMove.y))
            {
                //The close button has been hovered.
                if(m_closeShape != 0)
                {
                    m_closeShape->setFillColor(Config::getColor("NOTIFICATION_CLOSE_FILL_HOVER"));
                    m_closeShape->setOutlineColor(Config::getColor("NOTIFICATION_CLOSE_OUTLINE_HOVER"));
                }
                else
                {
                    m_closeIcon->setTextureRect(Config::getTextureManager()->getRect(Config::getString("NOTIFICATION_CLOSE_ICONTEX"),
                        Config::getString("NOTIFICATION_CLOSE_ICONTEX_RECT_HOVER"), 0));
                }
            }
            else
            {
                if(m_closeShape != 0)
                {
                    m_closeShape->setFillColor(Config::getColor("NOTIFICATION_CLOSE_FILL"));
                    m_closeShape->setOutlineColor(Config::getColor("NOTIFICATION_CLOSE_OUTLINE"));
                }
                else
                {
                    m_closeIcon->setTextureRect(Config::getTextureManager()->getRect(Config::getString("NOTIFICATION_CLOSE_ICONTEX"),
                        Config::getString("NOTIFICATION_CLOSE_ICONTEX_RECT"), 0));
                }
            }
        }

        return block;
    }
    void Notification::setBoundingBox(const sf::FloatRect &box)
    {
        Clickable::setBoundingBox(box);
        this->updateSize();
    }
    void Notification::updateSize()
    {
        Clickable::updateSize();
        m_icon->setPosition(m_boundingBox.left, m_boundingBox.top + m_boundingBox.width / 2 - m_icon->getGlobalBounds().height / 2);
        m_closeRect.left = m_boundingBox.left + m_boundingBox.width - 32;
        m_closeRect.top = m_boundingBox.top + m_boundingBox.height - 32;
    }

    void Notification::fromNotificationData(const NotificationData &data)
    {
        setTitle(data.getTitle());
        setDescription(data.getDescription());
        setIconTexture(data.getIconTexture());
        setIconTextureRect(data.getIconTextureRect());
        setIconTextureNumber(data.getIconTextureNumber());
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
    void Notification::setTitle(const std::string &title)
    {
        m_title->setString(title);
        m_titleString = title;
    }
    void Notification::setDescription(const std::string &description)
    {
        m_description->setString(description);
        m_descriptionString = description;
    }
    void Notification::setIconTexture(const std::string &texture)
    {
        m_icon->setTexture(Config::getTextureManager()->get(texture));
        m_texture = texture;
    }
    void Notification::setIconTextureRect(const std::string &rect)
    {
        m_textureRect = rect;
        m_icon->setTextureRect(Config::getTextureManager()->getRect(m_texture, m_textureRect, m_textureNumber));
    }
    void Notification::setIconTextureNumber(unsigned int number)
    {
        m_textureNumber = number;
        m_icon->setTextureRect(Config::getTextureManager()->getRect(m_texture, m_textureRect, m_textureNumber));
    }
    const std::string& Notification::getTitle()
    {
        return m_titleString;
    }
    const std::string& Notification::getDescription()
    {
        return m_descriptionString;
    }
    const std::string& Notification::getIconTexture()
    {
        return m_texture;
    }
    const std::string& Notification::getIconTextureRect()
    {
        return m_textureRect;
    }
    unsigned int Notification::getIconTextureNumber()
    {
        return m_textureNumber;
    }
}
