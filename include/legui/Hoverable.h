#pragma once

#include <legui/nano_signal_slot.hpp>
#include <legui/Widget.h>

namespace legui
{
    /**
     * @brief This widget is hoverable (by the mouse cursor without clicking).
     */
    class Hoverable : public Widget
    {
        public:
            Hoverable(Container *parent = 0);
            
            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);

            /**
             * @brief Checks if the widget is currently hovered.
             *
             * @return The current hover state.
             */
            bool isHovered();
            /**
             * @brief Immeadiate mode hook for the hover gained signal.
             */
            bool hoverGained();
            /**
             * @brief Immediate mode hook for the hover lost signal.
             */
            bool hoverLost();

            /**
             * @brief Is called when the mouse cursor enters the widget (the bounding box).
             *
             * @return The onHoverGained signal.
             */
            Nano::signal<void()>& onHoverGained();
            /**
             * @brief Is called when the mouse cursor leaves the widget (the bounding box).
             *
             * @return The onHoverLost signal.
             */
            Nano::signal<void()>& onHoverLost();

            /**
             * @brief Sets the current hover state.
             */
            void setHover(bool state);
        private:
            bool m_hoverGained;
            bool m_hoverLost;
            bool m_hover;
            Nano::signal<void()> m_onHoverGained;
            Nano::signal<void()> m_onHoverLost;
    };
}
