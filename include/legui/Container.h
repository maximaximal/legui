#pragma once

#include <legui/Widget.h>
#include <vector>

namespace legui
{
    class Container : public Widget
    {
        public:
            Container(Container *parent = 0);
            virtual ~Container();

            virtual void onUpdate(float frametime);
            virtual bool onEvent(const sf::Event &e);
            virtual void setBoundingBox(const sf::FloatRect &box);
            virtual void updateSize();

            /**
             * @brief Adds a widget to the container.
             *
             * The added widget will be completely managed by this container and 
             * will also be deleted by this container. Don't delete it from elsewhere!!
             *
             * @param widget The widget to be added.
             *
             * @return The iterator position of this widget;
             */
            std::size_t addWidget(Widget *widget);
            /**
             * @brief Removes a widget from the container (delete) (SLOW).
             *
             * @param widget The pointer to the widget to be removed.
             */
            void deleteWidget(Widget *widget);
            /**
             * @brief Removes a widget from the container (delete) (FASTEST).
             *
             * @param widget The iterator position of the widget to be deleted.
             */
            void deleteWidget(std::size_t widget);
            /**
             * @brief Removes the widget from this container (no longer managed) (SLOW).
             *
             * @param widget Pointer to the widget to be removed.
             */
            void removeWidget(Widget *widget);
            /**
             * @brief Removes the widget from this container (no longer managed) (FASTEST).
             *
             * @param widget The iterator position of the widget.
             */
            void removeWidget(std::size_t widget);
            /**
             * @brief Gets the internal widget vector.
             *
             * @return All widgets of this container.
             */
            std::vector<Widget*>& getWidgets();
            /**
             * @brief Gets the widget from the iterator position.
             *
             * @param widget The iterator position of the widget.
             *
             * @return The pointer to the widget. (It is still owned by this container.)
             */
            Container* getWidget(std::size_t widget);
            /**
             * @brief Clears (deletes) the whole container.
             */
            void clear();
            /**
             * @brief Gets the internal widget count (starts at 1).
             *
             * @return Internal widgets count.
             */
            std::size_t getSize();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
            std::vector<Widget*> m_widgets;
    };
};
