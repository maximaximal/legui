#pragma once

#include <string>

namespace legui
{
    class NotificationData
    {
        public: 
            NotificationData(const std::string &title, const std::string &description);
            virtual ~NotificationData();

            void setTitle(const std::string &title);
            void setDescription(const std::string &description);
            void setIconTexture(const std::string &iconTexture);
            void setIconTextureRect(const std::string iconTextureRect);
            void setIconTextureNumber(unsigned int number);

            const std::string& getTitle();
            const std::string& getDescription();
            const std::string& getIconTexture();
            const std::string& getIconTextureRect();
            unsigned int getIconTextureNumber();
        private:
            std::string m_title;
            std::string m_description;
            std::string m_texture;
            std::string m_textureRect;
            bool m_textureNumber;
    };
}
