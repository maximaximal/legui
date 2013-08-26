#pragma once

#include <legui/Container.h>
#include <legui/Scrollbar.h>

namespace legui
{
    class Scrollable : public Container
    {
        public:
            Scrollable(const sf::Vector2u &screenSize, Container *parent = 0);
            virtual ~Scrollable();

            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();
            void updateView();

            void setHScroll(float scroll);
            void setVScroll(float scroll);
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            Scrollbar *m_hBar;
            Scrollbar *m_vBar;
            bool m_hBarActive;
            bool m_vBarActive;
            sf::Vector2f m_internSize;
            sf::Vector2f m_offset;
            sf::Vector2u m_screenSize;
            sf::View *m_view;
    };
}
