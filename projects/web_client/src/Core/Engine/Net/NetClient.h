#pragma once

namespace JourneyOfDreams
{
    class NetworkConnection;

    class NetClient
    {
      public:
        NetClient();

        void Update();

        void BeginEstablishConnection();

        EMSCRIPTEN_RESULT Send(std::map<std::string, std::string> data);

        bool Connected();

        std::shared_ptr<NetworkConnection> Connection() const;

      private:
        std::shared_ptr<NetworkConnection> m_connection;
    };
}
