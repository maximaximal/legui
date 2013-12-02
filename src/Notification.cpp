#include <legui/Notification.h>
#include <legui/Config.h>
#include <legui/TextureManagerAbstract.h>
#include <legui/FontStyle.h>
#include <iostream>

using namespace std;

namespace legui
{
    Notification::Notification(Container *parent)
        : Clickable(parent)
    {
        m_closeIcon = 0;
        m_close = false;
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

        m_title->setStyle(FontStyle::Heading4);
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
        m_icon->setPosition(m_boundingBox.left + 5, m_boundingBox.top + m_boundingBox.height / 2 - m_icon->getGlobalBounds().height / 2);
        m_title->setBoundingBox(sf::FloatRect(m_boundingBox.left + 5 + m_icon->getGlobalBounds().width + 5, 
                m_boundingBox.top + 5, 
                m_boundingBox.width - m_icon->getGlobalBounds().width - 15,
                Config::getFloat("STANDARD_HEIGHT")));
        m_title->setWrap(m_boundingBox.width - m_icon->getGlobalBounds().width - 40);
        m_description->setBoundingBox(sf::FloatRect(m_boundingBox.left + 5 + m_icon->getGlobalBounds().width + 5, 
                m_title->getBoundingBox().top + m_title->getBoundingBox().height + 15,
                m_boundingBox.width - m_icon->getGlobalBounds().width - 15,
                Config::getFloat("STANDARD_HEIGHT")));
        m_description->setWrap(m_boundingBox.width - m_icon->getGlobalBounds().width - 40);
        m_boundingBox.height = m_title->getBoundingBox().height + m_description->getBoundingBox().height + 5;
        m_closeRect.left = m_boundingBox.left + m_boundingBox.width - 16;
        m_closeRect.top = m_boundingBox.top;
        if(m_closeShape != 0)
        {
            m_closeShape->setPosition(sf::Vector2f(m_closeRect.left, m_closeRect.top));
            m_closeShape->setSize(sf::Vector2f(m_closeRect.width, m_closeRect.height));
        }
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
    void Notification::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(*m_title, states);
        target.draw(*m_description, states);
        if(m_icon)
            target.draw(*m_icon, states);
        if(m_closeShape)
            target.draw(*m_closeShape, states);
        if(m_closeIcon)
            target.draw(*m_closeIcon, states);
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
        if(Config::getBool("USE_TEXTURES"))
        {
            m_icon->setTexture(Config::getTextureManager()->get(texture));
            m_texture = texture;
        }
    }
    void Notification::setIconTextureRect(const std::string &rect)
    {
        if(Config::getBool("USE_TEXTURES"))
        {
            m_textureRect = rect;
            m_icon->setTextureRect(Config::getTextureManager()->getRect(m_texture, m_textureRect, m_textureNumber));
        }
    }
    void Notification::setIconTextureNumber(unsigned int number)
    {
        if(Config::getBool("USE_TEXTURES"))
        {
            m_textureNumber = number;
            m_icon->setTextureRect(Config::getTextureManager()->getRect(m_texture, m_textureRect, m_textureNumber));
        }
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
