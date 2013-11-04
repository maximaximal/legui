#pragma once

#include <legui/nano_signal_slot.hpp>
#include <legui/Clickable.h>
#include <legui/LineEdit.h>

namespace legui
{
    class NumberInput : public legui::Clickable
    {
        public:
            NumberInput(Container *parent = 0);
            virtual ~NumberInput();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();

            Nano::signal<void(int)>& onChanged();
            int getValue();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
            virtual void D_onChanged(int newValue);
        private:
            Nano::signal<void(int)> m_onChanged;
            LineEdit *m_numberInput;
    };
}
