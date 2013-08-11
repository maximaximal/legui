#pragma once

#include <legui/Clickable.h>
#include <legui/Frame.h>
#include <legui/Label.h>

namespace legui
{
    class PushButton : public Clickable, public Frame
    {
        public:
            PushButton(Container *parent = 0);
            virtual ~PushButton();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();

            Label* getLabel();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

            virtual void D_onFocusGained();
            virtual void D_onFocusLost();
            virtual void D_onHoverGained();
            virtual void D_onHoverLost();
        private:
            Label *m_label;
    };
}

