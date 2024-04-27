#pragma once

namespace zw
{
    class ConfigurationFile
    {
      public:
        ConfigurationFile();
        auto ServerAddress() const
        {
            return m_serverAddress;
        }
        auto ServerPort() const
        {
            return m_serverPort;
        }

      private:
        std::string m_serverAddress{};
        int m_serverPort{};

        const std::string k_filePath{ "configuration/settings.cfg" };
    };
}
