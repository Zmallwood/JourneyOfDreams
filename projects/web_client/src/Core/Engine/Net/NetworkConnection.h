// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace journey_of_dreams
{
  /////////////////////////////////////////////////
  /// Network connection to the server.
  /////////////////////////////////////////////////
  class NetworkConnection {
   public:
    /////////////////////////////////////////////////
    /// Create connection and setup web socket callbacks.
    /////////////////////////////////////////////////
    void InitiateConnectToServer();

    /////////////////////////////////////////////////
    /// Send a message to the server.
    ///
    /// \param data The data to send.
    /// \return The result of the send operation.
    /////////////////////////////////////////////////
    EMSCRIPTEN_RESULT SendMessage(std::map<std::string, std::string> data);

    /////////////////////////////////////////////////
    /// Tells if the client is connected to the server.
    ///
    /// \return True if connected, false otherwise.
    /////////////////////////////////////////////////
    bool Connected() const;

    /////////////////////////////////////////////////
    /// Set the connected state.
    ///
    /// \param connected The connected state.
    /////////////////////////////////////////////////
    void SetConnected(bool connected);

    /////////////////////////////////////////////////
    /// Set the server socket object.
    ///
    /// \param serverSocket The server socket object.
    /////////////////////////////////////////////////
    void SetServerSocket(const EMSCRIPTEN_WEBSOCKET_T *serverSocket);

   private:
    bool m_connected{false};
    const EMSCRIPTEN_WEBSOCKET_T *m_serverSocket{nullptr};
  };
} // namespace journey_of_dreams
