#pragma once

#include <legui/Clickable.h>

namespace legui
{
    /**
     * @brief Describes a checkable widget. 
     *
     * Clickable with state-holding.
     */
    class Checkable : public legui::Clickable
    {
        public:
            Checkable(Container *parent = 0);
            virtual ~Checkable();
            
            bool isChecked() const;
            void setChecked(bool state);
            Nano::signal<void()>& onChecked();
            Nano::signal<void()>& onUnchecked();
        protected:
            virtual void D_checked();
            virtual void D_unchecked();
            virtual void D_onReleased(const sf::Vector2f &relPos);
            
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            bool m_state;
            Nano::signal<void()> m_onChecked;
            Nano::signal<void()> m_onUnchecked;
    };
}
