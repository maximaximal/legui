#pragma once

#include <legui/NotificationData.h>
#include <stack>

namespace legui {
class NotificationQueue {
  public:
  static const NotificationData& top();
  static bool newNotifications();
  static void pop();
  static void push(const NotificationData& data);

  private:
  NotificationQueue();
  ~NotificationQueue();

  static std::stack<NotificationData> m_notifications;
};
}
