#pragma once

#include <legui/Container.h>
#include <legui/Clickable.h>

namespace legui
{
    class NotificationsDisplay : public Container 
    {
        public: 
            NotificationsDisplay(Container *parent = 0);
            virtual ~NotificationsDisplay();

            virtual void onUpdate(float frametime);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();
        protected:
    };
}
