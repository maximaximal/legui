#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <legui/Widget.h>

namespace legui
{
    /**
     * @brief Displays a given percentage.
     */
    class ProgressBar : public Widget
    {
        public:
            ProgressBar(Container *parent = 0);
            virtual ~ProgressBar();

            virtual void setBoundingBox(const sf::FloatRect &box);
            /**
             * @brief Updates the internal rectangles.
             */
            virtual void updateSize();

            /**
             * @brief Sets the percent of the progress bar.
             *
             * Min: 0%
             * Max: 100%
             *
             * @param percent The percent.
             */
            void setPercent(float percent);
            /**
             * @brief Returns the current percentage of the widget.
             *
             * @return The percent.
             */
            float getPercent();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            sf::RectangleShape *m_leftShape;
            sf::RectangleShape *m_rightShape;

            float m_percent;
    };
}
