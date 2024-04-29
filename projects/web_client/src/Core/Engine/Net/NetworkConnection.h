#pragma once

namespace JourneyOfDreams
{
    class NetworkConnection
    {
      public:
        void InitiateConnectToServer();

        EMSCRIPTEN_RESULT SendMessage(std::map<std::string, std::string> data);

        auto Connected() const
        {
            return m_connected;
        }

        void SetConnected(bool connected)
        {
            m_connected = connected;
        }

        void SetServerSocket(const EMSCRIPTEN_WEBSOCKET_T *serverSocket)
        {
            m_serverSocket = serverSocket;
        }

      private:
        bool m_connected{ false };
        const EMSCRIPTEN_WEBSOCKET_T *m_serverSocket{ nullptr };
    };
}
