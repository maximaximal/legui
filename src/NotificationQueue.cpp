#include <legui/NotificationQueue.h>

namespace legui
{
    std::stack<NotificationData> NotificationQueue::m_notifications = std::stack<NotificationData>();

    NotificationQueue::NotificationQueue()
    {
        //Nothing to do (Static Class).
    }
    NotificationQueue::~NotificationQueue()
    {
        //Nothing to do (Static Class).
    }
    
    const NotificationData& NotificationQueue::top()
    {
        return m_notifications.top();
    }
    void NotificationQueue::pop()
    {
        m_notifications.pop();
    }
    void NotificationQueue::push(NotificationData &data)
    {
        m_notifications.push(data);
    }
}
