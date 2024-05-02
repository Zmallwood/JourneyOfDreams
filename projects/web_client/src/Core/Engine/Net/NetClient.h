//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams
{
    class NetworkConnection;

    /////////////////////////////////////////////////
    /// Manages the network communication to the server.
    /////////////////////////////////////////////////
    class NetClient
    {
      public:
        /////////////////////////////////////////////////
        /// Create the network connection object.
        /////////////////////////////////////////////////
        NetClient();

        /////////////////////////////////////////////////
        /// Update the network connection logic.
        /////////////////////////////////////////////////
        void Update();

        /////////////////////////////////////////////////
        /// Begin the connection process to the server.
        /////////////////////////////////////////////////
        void BeginEstablishConnection();

        /////////////////////////////////////////////////
        /// Send a message to the server.
        ///
        /// \param data The data in json format to send to the server.
        /// \return The result of the operation.
        /////////////////////////////////////////////////
        EMSCRIPTEN_RESULT Send(std::map<std::string, std::string> data);

        /////////////////////////////////////////////////
        /// Tells if the client is connected to the server.
        ///
        /// \return True if the client is connected to the server.
        /////////////////////////////////////////////////
        bool Connected();

        /////////////////////////////////////////////////
        /// Get the network connection object.
        ///
        /// \return The network connection object.
        /////////////////////////////////////////////////
        std::shared_ptr<NetworkConnection> Connection() const;

      private:
        std::shared_ptr<NetworkConnection> m_connection;
    };
}
