#pragma once

#include <stack>
#include <legui/NotificationData.h>

namespace legui
{
    class NotificationQueue
    {
        public:
            static const NotificationData& top();
            static void pop();
            static void push(NotificationData &data);
        private:
            NotificationQueue();
            ~NotificationQueue();

            static std::stack<NotificationData> m_notifications;
    };
}
