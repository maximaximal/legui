#pragma once

#include <legui/Widget.h>
#include <vector>

namespace legui {
class PageManager;
/**
 * @brief Base class for every widget that can hold other widgets.
 *
 * All container widgets have to derive from this!.
 */
class Container : public Widget {
  public:
  Container(Container* parent = 0);
  virtual ~Container();

  virtual void onUpdate(float frametime);
  virtual bool onEvent(const sf::Event& e);
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
  std::size_t addWidget(Widget* widget);
  /**
   * @brief Removes a widget from the container (delete) (SLOW).
   *
   * @param widget The pointer to the widget to be removed.
   */
  void deleteWidget(Widget* widget);
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
  void removeWidget(Widget* widget);
  /**
   * @brief Removes the widget from this container (no longer managed)
   * (FASTEST).
   *
   * @param widget The iterator position of the widget.
   */
  void removeWidget(std::size_t widget);
  /**
   * @brief Sets the page manager which manages this container.
   *
   * @param pageManager The managing page manager.
   */
  void setPageManager(PageManager* pageManager);
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
  /**
   * @brief Returns the page manager that controls this container.
   *
   * If the container is not managed by a page manager, then this returns 0.
   *
   * @return The managing page manager.
   */
  PageManager* getPageManager();

  protected:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  std::vector<Widget*> m_widgets;
  PageManager* m_pageManager;
  /**
   * @brief Deriveable callback which is fired when a widget is added to the
   * container.
   *
   * @param widget The widget that was added.
   */
  virtual void D_widgetAdded(Widget* widget);
  /**
   * @brief Deriveable callback which is fired when a widget is removed from the
   * container. (Also called on clear())
   *
   * @param widget The widget that was removed.
   */
  virtual void D_widgetRemoved(Widget* widget);
};
}
