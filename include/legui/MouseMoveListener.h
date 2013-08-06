#pragma once

#include <legui/Widget.h>

namespace legui
{
    /**
     * @brief Handles Mouse Moves (computes delta move) for derived widgets.
     */
    class MouseMoveListener : public Widget
    {
        public:
            MouseMoveListener(Container *parent = 0);

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
        protected:
            /**
             * @brief Called when the mouse is moved.
             *
             * @param delta The delta move of the mouse position.
             */
            virtual void mouseMoved(sf::Vector2f delta);
        private:
            sf::Vector2f m_oldMousePos;
    };
}
