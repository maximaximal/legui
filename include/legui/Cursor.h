#pragma once 

#include <SFML/Graphics/RectangleShape.hpp>
#include <legui/Widget.h>

namespace legui
{
    class Cursor : public Widget
    {
        public:
            Cursor(Container *parent = 0);
            virtual ~Cursor();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            
            /**
             * @brief Resets the internal blink timer (to 0 seconds).
             */
            void resetBlinkTimer();
            void refresh();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            float m_blinkTimer;
            sf::RectangleShape *m_backgroundRect;
            bool m_state;
    };
}
