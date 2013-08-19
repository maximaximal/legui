#pragma once

namespace legui
{
    class NotificationQueue
    {
        public:
            static const NotificationData& getNewest();
            static const NotificationData& getOldest();
            static void popNewest();
            static void popOldest();
        private:
            NotificationQueue();
            ~NotificationQueue();

            static std::stack<NotificationData> m_notifications;
    };
}
