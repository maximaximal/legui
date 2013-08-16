#pragma once

#include <legui/Container.h>

namespace legui
{
    /**
     * @brief Alignes the containing widgets vertically in 2 rows.
     */
    class HorizontalSplitter : public Container
    {
        public:
            HorizontalSplitter(Container *parent = 0);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();
            
            /**
             * @brief Sets the padding between the internal widgets. 
             *
             * The padding is applied between the containing elements (left & right of the middle strip).
             *
             * @param padding The padding in pixels.
             */
            void setPadding(float padding = 0);
            /**
             * @brief Returns the padding between the internal widgets.
             *
             * @return The padding in pixels.
             */
            float getPadding();
        private:
            float m_padding;
    };
}
