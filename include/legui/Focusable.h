#pragma once

#include <legui/nano_signal_slot.hpp>
#include <legui/Hoverable.h>

namespace legui
{
    /**
     * @brief This widget is focusable (by tabbing through the widgets).
     */
    class Focusable : public Hoverable
    {
        public:
            Focusable(Container *parent = 0);

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            /**
             * @brief Checks if the widget is currently focused.
             */
            bool isFocused();
            /**
             * @brief Immediate mode hook for the gained focus signal.
             */
            bool gainedFox();
            /**
             * @brief Immediate mode hook for the lost focus signal.
             */
            bool lostFocus();
            /**
             * @brief Is called when the focus comes to this widget.
             *
             * @return 
             */
            Nano::signal<void()>& onFocusGained();
            /**
             * @brief Is called when the focus goes from this widget.
             */
            Nano::signal<void()>& onFocusLost();
            
            /**
             * @brief Sets the next focusable widget which is selected once the "Tab" key is pressed.
             *
             * Does nothing by default (leaves the focus on this widget).
             *
             * @param next Pointer to the next focusable widget.
             */
            void setNextFocusable(Focusable *next);
            /**
             * @brief Sets the focus of the widget.
             *
             * @param state Focus state.
             */
            void setFocus(bool state);
        protected:
            /**
             * @brief Derivable function for the focus gained signal.
             */
            virtual void D_onFocusGained();
            /**
             * @brief Derivable function for the focus lost signal.
             */
            virtual void D_onFocusLost();
        private:
            bool m_isFocused;
            bool m_focusGained;
            bool m_focusLost;
            Nano::signal<void()> m_onFocusGained;
            Nano::signal<void()> m_onFocusLost;
            Focusable *m_nextFocusable;
    };
}
