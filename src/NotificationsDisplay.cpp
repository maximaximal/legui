#include <iostream>
#include <legui/Config.h>
#include <legui/NotificationQueue.h>
#include <legui/NotificationsDisplay.h>

using namespace std;

namespace legui {
NotificationsDisplay::NotificationsDisplay(Container* parent)
  : Container(parent) {
  m_updateAgain = false;
}
NotificationsDisplay::~NotificationsDisplay() {}
void
NotificationsDisplay::onUpdate(float frametime) {
  // Query the notification queue
  bool update = false;
  while(NotificationQueue::newNotifications()) {
    std::unique_ptr<legui::Notification> newNotify(new Notification());
    newNotify->setParent(this);
    newNotify->fromNotificationData(NotificationQueue::top());
    m_notifications.push_back(std::move(newNotify));
    NotificationQueue::pop();
    update = true;
    m_updateAgain = true;
  }

  m_notifications.erase(
    std::remove_if(m_notifications.begin(),
                   m_notifications.end(),
                   [&](unique_ptr<Notification> const& p) -> bool {
                     if(p->onClose())
                       update = true;
                     m_updateAgain = true;
                     return p->onClose();
                   }),
    m_notifications.end());

  // Update the containing elements after checking the closed states.
  Container::onUpdate(frametime);

  for(auto& it : m_notifications) {
    it->onUpdate(frametime);
  }

  // Update the size if requested.
  if(update || m_updateAgain) {
    updateSize();
    if(!update)
      m_updateAgain = false;
  }
}
void
NotificationsDisplay::setBoundingBox(const sf::FloatRect& box) {
  Container::setBoundingBox(box);
  this->updateSize();
}
void
NotificationsDisplay::updateSize() {
  std::size_t i;
  float x = m_boundingBox.top;
  sf::FloatRect box = m_boundingBox;
  for(i = 0; i < m_notifications.size(); ++i) {
    if(i > 0)
      x = x + m_notifications[i - 1]->getBoundingBox().height +
          Config::getInt("NOTIFICATIONLIST_MARGIN");
    box.top = x;
    m_notifications[i]->setBoundingBox(box);
  }
}
bool
NotificationsDisplay::onEvent(const sf::Event& e) {
  Container::onEvent(e);
  for(auto& it : m_notifications) {
    it->onEvent(e);
  }
}
void
NotificationsDisplay::draw(sf::RenderTarget& target,
                           sf::RenderStates states) const {
  for(auto& it : m_notifications) {
    target.draw(*it, states);
  }
}
}
