#pragma once

#include <legui/Widget.h>
#include <SFML/Graphics/RectangleShape.hpp>

namespace legui
{
    class Frame : public Widget
    {
        public:
            Frame(Container *parent = 0);
            virtual ~Frame();
            
            virtual void setBoundingBox(const sf::FloatRect &box);

            void setOutlineColor(const sf::Color &color);
            void setFillColor(const sf::Color &color);
            void setOutlineThickness(float thickness);
            const sf::Color& getOutlineColor();
            const sf::Color& getFillColor();
            float getOutlineThickness();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            sf::RectangleShape *m_rectangleShape;
    };
};
