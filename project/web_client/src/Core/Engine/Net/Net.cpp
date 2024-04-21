#include "Net.h"
#include "NetworkConnection.h"

namespace zw
{
    Net::Net() : m_connection(std::make_shared<NetworkConnection>())
    {
    }

    void Net::BeginEstablishConnection()
    {
        m_connection->InitiateConnectToServer();
    }

    EMSCRIPTEN_RESULT Net::Send(std::map<std::string, std::string> data)
    {
        return m_connection->SendMessage(data);
    }

    void Net::Update()
    {
    }

    bool Net::Connected()
    {
        return m_connection->Connected();
    }
}
