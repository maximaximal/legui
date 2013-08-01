#pragma once

#include <legui/Container.h>

namespace legui
{
    class HorizontalSplitter : public Container
    {
        public:
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();
    };
};
