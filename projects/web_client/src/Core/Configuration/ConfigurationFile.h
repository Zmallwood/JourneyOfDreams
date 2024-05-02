//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams
{
    class ConfigurationFile
    {
      public:
        /////////////////////////////////////////////////
        /// Read the configuration file and store
        /// the values in the class.
        /////////////////////////////////////////////////
        ConfigurationFile();

        /////////////////////////////////////////////////
        /// Gets the server address from the
        /// configuration file that has been read.
        ///
        /// \return Server address.
        /////////////////////////////////////////////////
        std::string ServerAddress() const;

        /////////////////////////////////////////////////
        /// Gets the server port from the
        /// configuration file that has been read.
        ///
        /// \return Server port.
        /////////////////////////////////////////////////
        int ServerPort() const;

      private:
        std::string m_serverAddress{};
        int m_serverPort{};
        const std::string k_filePath{ "configuration/settings.cfg" };
    };
}
