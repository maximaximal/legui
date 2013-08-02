#pragma once

#include <legui/nano_signal_slot.hpp>
#include <legui/Widget.h>

namespace legui
{
    class Hoverable : public Widget
    {
        public:
            Hoverable(Container *parent = 0);
            
            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);

            bool isHovered();
            bool hoverGained();
            bool hoverLost();

            Nano::signal<void()>& onHoverGained();
            Nano::signal<void()>& onHoverLost();

            void setHover(bool state);
        private:
            bool m_hoverGained;
            bool m_hoverLost;
            bool m_hover;
            Nano::signal<void()> m_onHoverGained;
            Nano::signal<void()> m_onHoverLost;
    };
}
