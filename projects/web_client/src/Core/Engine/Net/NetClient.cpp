#include "NetClient.h"
#include "NetworkConnection.h"

namespace zw
{
    NetClient::NetClient() : m_connection(std::make_shared<NetworkConnection>())
    {
    }

    void NetClient::BeginEstablishConnection()
    {
        m_connection->InitiateConnectToServer();
    }

    // EMSCRIPTEN_RESULT NetClient::Send(std::map<std::string, std::string> data)
    // {
    //     return m_connection->SendMessage(data);
    // }

    void NetClient::Send(std::map<std::string, std::string> data)
    {
        //return m_connection->SendMessage(data);
    }

    void NetClient::Update()
    {
    }

    bool NetClient::Connected()
    {
        return m_connection->Connected();
    }
}
