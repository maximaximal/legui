#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>

/**
 * @brief The main namespace of legui.
 */
namespace legui
{
    /**
     * @brief Describes the standard interface to a widget.
     *
     * All widgets are children of this class and maybe re-implement some functions.
     */
    class Widget : public sf::Drawable
    {
        public:
            Widget(Widget *parent = 0);
            virtual ~Widget();
        
            /**
             * @brief Called every frame.
             *
             * @param frametime The time the frame took in seconds.
             */
            virtual void onUpdate(float frametime);
            /**
             * @brief Called on every event.
             *
             * @param e The window event that happened.
             *
             * @return Blocking-Flag (true if the event is catched and shouldn't be processed further; false if else)
             */
            virtual bool onEvent(const sf::Event &e);
            /**
             * @brief Sets the internal bounding box (position & size).
             *
             * @param box The new bounding box.
             */
            virtual void setBoundingBox(const sf::FloatRect &box);
            /**
             * @brief Updates the internal bounding box & the parent's size.
             *
             * This is called when, for example, the content of a widget changes and a new size 
             * of the parent has to be computed. 
             *
             * Takes all child elements and computes the new size based on their sizes.
             */
            virtual void updateSize();

            /**
             * @brief Sets the parent of this widget.
             *
             * This is needed for chuildren of container widgets.
             *
             * @param parent The new widget parent.
             */
            virtual void setParent(legui::Widget *parent);

            /**
             * @brief Gets the parent of this widget.
             *
             * @return The widget parent.
             */
            Widget* getParent();
            /**
             * @brief Gets the bounding box of this widget.
             *
             * @return The bounding box.
             */
            const sf::FloatRect& getBoundingBox();
        protected:
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
            sf::FloatRect m_boundingBox;
            Widget *m_parent;
    };
};
