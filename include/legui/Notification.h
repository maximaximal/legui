#pragma once

#include <legui/Clickable.h>
#include <legui/NotificationData.h>
#include <SFML/Graphics/Sprite.hpp>

namespace legui
{
    class Notification : public Clickable
    {
        public:
            Notification(Container *parent = 0);
            virtual ~Notification();

            virtual void onUpdate(float frametime);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();

            void fromNotificationData(const NotificationData &data);
            bool onClose();
            void close();
        protected:
            virtual void D_onClicked(const sf::Vector2f &relPos);
        private:
            sf::Sprite *m_icon;
            sf::Sprite *m_closeIcon;
            bool m_close;
    };
}
