#pragma once

#include <legui/nano_signal_slot.hpp>
#include <legui/Hoverable.h>

namespace legui
{
    class Focusable : public Hoverable
    {
        public:
            Focusable(Container *parent = 0);

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            bool isFocused();
            bool gainedFox();
            bool lostFocus();
            Nano::signal<void()>& onFocusGained();
            Nano::signal<void()>& onFocusLost();
            
            void setNextFocusable(Focusable *next);
            void setFocus(bool state);
        private:
            bool m_isFocused;
            bool m_focusGained;
            bool m_focusLost;
            Nano::signal<void()> m_onFocusGained;
            Nano::signal<void()> m_onFocusLost;
            Focusable *m_nextFocusable;
    };
}
