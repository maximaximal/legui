#pragma once

#include <legui/nano_signal_slot.hpp>
#include <legui/Focusable.h>

namespace legui
{
    /**
     * @brief This widget is clickable (with the mouse).
     *
     * When the widget is focused, the Return key also triggers the signals.
     */
    class Clickable : public Focusable
    {
        public:
            Clickable(Container *parent = 0);
            /**
             * @brief Checks if the widget is currently clicked (pressed).
             *
             * @return The current state.
             */
            bool isPressed();
            /**
             * @brief Immediate GUI hook to detect if the widget is clicked.
             *
             * @return True if the button was pressed in this frame.
             */
            bool pressed();
            /**
             * @brief Immediate GUI hook to detect if the widget is released.
             *
             * @return True if the button was released in this frame.
             */
            bool released();
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
            /**
             * @brief Sets the current pressed-state of the widget.
             *
             * @param state The pressed state.
             */
            void setPressed(bool state);
        private:
            Nano::signal<void()> m_onPressed;
            Nano::signal<void()> m_onUnPressed;

            bool m_pressed, m_isButtonPressed, m_isButtonUnpressed;
    };
}
