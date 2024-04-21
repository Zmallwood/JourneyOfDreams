#include "NetworkConnection.h"
#include "Net.h"

namespace zw
{
    EM_BOOL OnOpen(int eventType, const EmscriptenWebSocketOpenEvent *websocketEvent, void *userData)
    {
        puts("onopen");
        std::cout << "connected\n";
        EMSCRIPTEN_RESULT result;
        result = emscripten_websocket_send_utf8_text(websocketEvent->socket,
                                                     "{\"__MESSAGE__\":\"message\", \"test\":\"hej\"}");
        if (result)
        {
            printf("Failed to emscripten_websocket_send_utf8_text(): %d\n", result);
        }
        std::cout << "sent message\n";
        _<Net>().Connection()->SetConnected(true);
        _<Net>().Connection()->SetServerSocket(&websocketEvent->socket);
        return EM_TRUE;
    }

    EMSCRIPTEN_RESULT NetworkConnection::SendMessage(std::map<std::string, std::string> data)
    {
        std::string json;
        json = "{";
        json += "\"__MESSAGE__\":\"message\",";
        for (auto &pair : data)
        {
            json += "\"" + pair.first + "\":\"" + pair.second + "\",";
        }
        json += "}";
        auto result = emscripten_websocket_send_utf8_text(*m_serverSocket, json.c_str());
        if (result)
        {
            printf("Failed to emscripten_websocket_send_utf8_text(): %d\n", result);
        }
        return result;
    }

    EM_BOOL OnError(int eventType, const EmscriptenWebSocketErrorEvent *websocketEvent, void *userData)
    {
        puts("onerror");

        return EM_TRUE;
    }

    EM_BOOL OnClose(int eventType, const EmscriptenWebSocketCloseEvent *websocketEvent, void *userData)
    {
        puts("onclose");

        return EM_TRUE;
    }

    EM_BOOL OnMessage(int eventType, const EmscriptenWebSocketMessageEvent *websocketEvent, void *userData)
    {
        puts("onmessage");
        if (websocketEvent->isText)
        {
            // For only ascii chars.
            printf("message: %s\n", websocketEvent->data);
        }

        // EMSCRIPTEN_RESULT result;
        // result = emscripten_websocket_close(websocketEvent->socket, 1000, "no reason");
        // if (result)
        //{
        //     printf("Failed to emscripten_websocket_close(): %d\n", result);
        // }
        return EM_TRUE;
    }

    void NetworkConnection::InitiateConnectToServer()
    {
        if (!emscripten_websocket_is_supported())
            return;

        EmscriptenWebSocketCreateAttributes ws_attrs = { "ws://localhost:1238", NULL, EM_TRUE };

        EMSCRIPTEN_WEBSOCKET_T ws = emscripten_websocket_new(&ws_attrs);
        emscripten_websocket_set_onopen_callback(ws, NULL, OnOpen);
        emscripten_websocket_set_onerror_callback(ws, NULL, OnError);
        emscripten_websocket_set_onclose_callback(ws, NULL, OnClose);
        emscripten_websocket_set_onmessage_callback(ws, NULL, OnMessage);
    }
}
