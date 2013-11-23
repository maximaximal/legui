#pragma once

#include <legui/Clickable.h>
#include <legui/Label.h>
#include <legui/NotificationData.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace legui
{
    class Notification : public Clickable
    {
        public:
            Notification(Container *parent = 0);
            virtual ~Notification();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();

            void setTitle(const std::string &title);
            void setDescription(const std::string &description);
            void setIconTexture(const std::string &iconTexture);
            void setIconTextureRect(const std::string &iconTextureRect);
            void setIconTextureNumber(unsigned int number);

            const std::string& getTitle();
            const std::string& getDescription();
            const std::string& getIconTexture();
            const std::string& getIconTextureRect();
            unsigned int getIconTextureNumber();
            
            void fromNotificationData(const NotificationData &data);
            bool onClose();
            void close();
        protected:
            virtual void D_onClicked(const sf::Vector2f &relPos);
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            sf::Sprite *m_icon;
            sf::Sprite *m_closeIcon;
            sf::RectangleShape *m_closeShape;
            sf::FloatRect m_closeRect;
            sf::Vector2i m_iconRect;
            
            legui::Label *m_title;
            legui::Label *m_description;

            std::string m_texture;
            std::string m_textureRect;
            std::string m_titleString;
            std::string m_descriptionString;
            bool m_textureNumber;
            bool m_close;
    };
}
