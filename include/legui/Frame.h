#pragma once

#include <legui/Widget.h>
#include <SFML/Graphics/RectangleShape.hpp>

namespace legui
{
    /**
     * @brief A frame around the bounding box.
     *
     * Frames can be derived from other widgets to provide
     * a background (or surrounding) frame around them.
     */
    class Frame : public Widget
    {
        public:
            /**
             * @brief Constructs a new Frame.
             *
             * @param parent The parent Container Widget.
             */
            Frame(Container *parent = 0);
            /**
             * @brief Destructor
             */
            virtual ~Frame();
            
            /**
             * @brief Sets the size & position of the internal sf::RectangleShape.
             *
             * @param box New bounding box.
             */
            virtual void setBoundingBox(const sf::FloatRect &box);

            /**
             * @brief Sets the outline color of the internal sf::RectangleShape.
             *
             * @param color The outlne color.
             */
            void setOutlineColor(const sf::Color &color);
            /**
             * @brief Sets the fill color of the internal sf::RectangleShape.
             *
             * @param color The fill color.
             */
            void setFillColor(const sf::Color &color);
            /**
             * @brief Sets the outline thickness of the internal sf::RectnagleShape.
             *
             * The outline is not added to the bounding box, it is just drawed
             * on the screen without layout changes.
             *
             * @param thickness The thickness in pixels. (>0 is out, <0 is in)
             */
            void setOutlineThickness(float thickness);
            /**
             * @brief Gets the outline color of the internal sf::RectangleShape.
             *
             * @return The outline color. 
             */
            const sf::Color& getOutlineColor();
            /**
             * @brief Gets the fill color of the internal sf::RectnagleShape.
             *
             * @return The fill color.
             */
            const sf::Color& getFillColor();
            /**
             * @brief Gets the outline thickness.
             *
             * @return Thickness in pixels. 
             */
            float getOutlineThickness();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            sf::RectangleShape *m_rectangleShape;
    };
}
