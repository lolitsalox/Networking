#pragma once

#include "Socket.hpp"

namespace Network
{
    class TcpServer
    {
    public:
        TcpServer(const uint16_t port, const uint32_t backlog = SOMAXCONN);
        virtual ~TcpServer();
        TcpServer(const TcpServer&) = delete;
        TcpServer& operator=(const TcpServer&) = delete;
        TcpServer(TcpServer&&) = delete;
        TcpServer& operator=(TcpServer&&) = delete;

        SocketUPtr accept();

    private:
        static SocketUPtr _s_create_server(const uint16_t port, const uint32_t backlog);
        static void _s_bind(SOCKET socket, const uint16_t port);
        static void _s_listen(SOCKET socket, const uint32_t backlog);

    private:
        SocketUPtr m_socket;
    };
}
