#pragma once

namespace zw
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

        auto Connection() const
        {
            return m_connection;
        }

      private:
        std::shared_ptr<NetworkConnection> m_connection;
    };
}
