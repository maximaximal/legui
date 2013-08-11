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
     *
     * Do not use the container methods - use the pagemanager ones!!
     */
    class PageManager : public Container
    {
        public:
            PageManager();
            virtual ~PageManager();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();
            
            /**
             * @brief Pushes a new page ontop of the stack & makes it active.
             *
             * @param container The new page.
             */
            void push(Container *container);
            /**
             * @brief Replaces & deletes the current page.
             *
             * @param container The new page.
             */
            void replaceCurrent(Container *container);
            /**
             * @brief Deletes the page under the current one.
             */
            void popUnder();
            /**
             * @brief Deletes the specified page.
             *
             * @param page The page ID to be deleted.
             */
            void pop(std::size_t page);
            /**
             * @brief Pops (deletes) the page on the top & makes the page below the new current page.
             */
            void pop();
            /**
             * @brief Returns the current page.
             *
             * @return The current page.
             */
            Container* top();
            /**
             * @brief Returns the specified page.
             *
             * @param page The page id of the requested page.
             *
             * @return The requested page.
             */
            Container* get(std::size_t page);
            /**
             * @brief Gets the current page id (of the page ontop).
             *
             * @return The currenz page id.
             */
            std::size_t getCurrentPageId();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        private:
            std::size_t m_currentPage;
            bool m_screenSizeChanged;
            bool m_updateSizeRequested;
    };
}
