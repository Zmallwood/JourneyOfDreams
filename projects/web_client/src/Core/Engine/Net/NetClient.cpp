#include "NetClient.h"
#include "NetworkConnection.h"

namespace JourneyOfDreams
{
    NetClient::NetClient() : m_connection(std::make_shared<NetworkConnection>())
    {
    }

    void NetClient::BeginEstablishConnection()
    {
        m_connection->InitiateConnectToServer();
    }

    EMSCRIPTEN_RESULT NetClient::Send(std::map<std::string, std::string> data)
    {
        return m_connection->SendMessage(data);
    }

    void NetClient::Update()
    {
    }

    bool NetClient::Connected()
    {
        return m_connection->Connected();
    }

    std::shared_ptr<NetworkConnection> NetClient::Connection() const
    {
        return m_connection;
    }
}
