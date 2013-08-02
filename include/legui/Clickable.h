#pragma once

#include <legui/nano_signal_slot.hpp>
#include <legui/Widget.h>

namespace legui
{
    class Clickable : public Widget
    {
        public:
            /**
             * @brief Immediate GUI hook to detect if the widget is clicked.
             *
             * @return True if the button was pressed in this frame.
             */
            bool isButtonPressed();
            /**
             * @brief Immediate GUI hook to detect if the widget is released.
             *
             * @return True if the button was released in this frame.
             */
            bool isButtonReleased();
            /**
             * @brief Triggered when the mouse has clicked in the bounding box.
             *
             * @return The signal to connect to.
             */
            Nano::signal<void()>& onPressed();
            /**
             * @brief Triggered when the mouse has un-pressed the previously clicked key.
             *
             * @return The signal to connect to.
             */
            Nano::signal<void()>& onUnPressed();

            virtual bool onEvent(const sf::Event &e);
            /**
             * @brief Resets the internal pressed states every frame.
             */
            virtual void onUpdate(float frametime);
        private:
            Nano::signal<void()> m_onPressed;
            Nano::signal<void()> m_onUnPressed;

            bool m_isButtonPressed, m_isButtonUnpressed;
    };
}
