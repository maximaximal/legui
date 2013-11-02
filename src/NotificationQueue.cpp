#include <legui/NotificationQueue.h>

namespace legui
{
    std::stack<NotificationData> NotificationQueue::m_notifications = std::stack<NotificationData>();

    NotificationQueue::NotificationQueue()
    {
        //Nothing to do.
    }
    NotificationQueue::~NotificationQueue()
    {
        //Nothing to do.
    }
    const NotificationData& NotificationQueue::top() 
    {
        return m_notifications.top();
    }
    void NotificationQueue::pop()
    {
        m_notifications.pop();
    }
    void NotificationQueue::push(const NotificationData &data)
    {
        m_notifications.push(data);
    }
}
