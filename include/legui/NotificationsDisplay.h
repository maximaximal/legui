#pragma once

#include <memory>
#include <vector>
#include <legui/Container.h>
#include <legui/Clickable.h>
#include <legui/Notification.h>

namespace legui
{
    class NotificationsDisplay : public Container 
    {
        public: 
            NotificationsDisplay(Container *parent = 0);
            virtual ~NotificationsDisplay();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
            std::vector<std::unique_ptr<Notification> > m_notifications;
            bool m_updateAgain;
    };
}
