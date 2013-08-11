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
             * @brief Get relative position of the click (relative to upper left)
             *
             * @return The relative position.
             */
            const sf::Vector2f& getRelPos();
            /**
             * @brief Triggered when the mouse has clicked in the bounding box.
             *
             * @return The signal to connect to.
             */
            Nano::signal<void(const sf::Vector2f&)>& onPressed();
            /**
             * @brief Triggered when the mouse has un-pressed the previously clicked key.
             *
             * @return The signal to connect to.
             */
            Nano::signal<void(const sf::Vector2f&)>& onUnPressed();

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
        protected:
            /**
             * @brief Derivable function for the clicked signal.
             */
            virtual void D_onClicked(const sf::Vector2f &relPos);
            /**
             * @brief Derivable function for the released signal.
             */
            virtual void D_onReleased(const sf::Vector2f &relPos);
        private:
            Nano::signal<void(const sf::Vector2f&)> m_onPressed;
            Nano::signal<void(const sf::Vector2f&)> m_onUnPressed;

            bool m_pressed, m_isButtonPressed, m_isButtonUnpressed;
            sf::Vector2f m_relPos;
    };
}
