#pragma once

#include <legui/Container.h>

namespace legui
{
    /**
     * @brief Manages gui pages and their required updates.
     *
     * The gui is built ontop of pages, which are stacked like a 
     * stack of paper. You push new pages ontop of it and pop it afterwards.
     *
     * If there is a new page without the possibility to go back, then you 
     * also are allowed to delete a specific page, to replace the current one, or
     * to delete the previous one.
     */
    class PageManager : protected Container
    {
        public:
            PageManager();
            virtual ~PageManager();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();
            
            void push(Container *container);
            void replaceCurrent(Container *container);
            void popUnder();
            void pop(std::size_t page);
            void pop();
            Container* top();
            Container* get(std::size_t page);
            std::size_t getCurrentPageId();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            std::size_t m_currentPage;
            bool m_screenSizeChanged;
            bool m_updateSizeRequested;
    };
}
