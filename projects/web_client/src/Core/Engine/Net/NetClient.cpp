/* Copyright (c) 2024 Andreas Åkerberg. */

#include "NetClient.h"
#include "NetworkConnection.h"

/* NetClient class implementation. */

namespace JourneyOfDreams
{
  NetClient::NetClient()
      : m_connection(std::make_shared<NetworkConnection>()) {
    /*
    ** Do nothing. */
  }

  void NetClient::BeginEstablishConnection() {
    /*
    ** Try connect. */
    m_connection->InitiateConnectToServer();
  }

  EMSCRIPTEN_RESULT
  NetClient::Send(std::map<std::string, std::string> data) {
    /*
    ** Forward function call to connection object. */
    return m_connection->SendMessage(data);
  }

  void NetClient::Update() {
    /*
    ** To implement: Update of network logic. */
  }

  bool NetClient::Connected() {
    /*
    ** Getter. */
    return m_connection->Connected();
  }

  std::shared_ptr<NetworkConnection> NetClient::Connection() const {
    /*
    ** Getter. */
    return m_connection;
  }
}