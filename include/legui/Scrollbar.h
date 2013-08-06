#pragma once

#include <legui/MouseMoveListener.h>
#include <legui/Clickable.h>

namespace legui
{
    class Scrollbar : public Clickable, public MouseMoveListener
    {
        public:
            enum Align {
                Vertical,
                Horizontal
            };
            Scrollbar(Container *parent = 0);
            virtual ~Scrollbar();
            
            virtual void onUpdate(float frametime);
            virtual void onEvent(const sf::Event &e);
            /**
             * @brief Needs the boundng box of the parent scrollable area.
             */
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();

            void setAlign(Scrollbar::Align align);
            void setScrollable(Scrollable *scrollable);
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
            virtual void mouseMoved(sf::Vector2f delta);
        private:
            sf::RectangleShape *m_bar;
            sf::VertexArray m_middleLines;

            Scrollable *m_scrollable;
            Scrollbar::Align m_align;
            sf::Vector2f m_scrollArea;
    };
}
