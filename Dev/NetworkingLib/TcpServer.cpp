#include "pch.hpp"
#include "NetworkException.hpp"
#include "TcpServer.hpp"

namespace Network
{
    TcpServer::TcpServer(const uint16_t port, const uint32_t backlog) :
        m_socket(_s_create_server(port, backlog))
    {}

    TcpServer::~TcpServer()
    {
        try
        {
            ::shutdown(m_socket->get_handle(), SD_BOTH);
        }
        catch (...) {}
    }

    SocketUPtr TcpServer::accept()
    {
        sockaddr_in addr;
        SOCKET socket = ::accept(m_socket->get_handle(), reinterpret_cast<SOCKADDR*>(&addr), nullptr);
        if (INVALID_SOCKET == socket)
        {
            throw Exception(Status::TCPSERVER_ACCEPT_ACCEPT_FAILED, WSAGetLastError());
        }
        return std::make_unique<Socket>(socket);
    }

    SocketUPtr TcpServer::_s_create_server(const uint16_t port, const uint32_t backlog)
    {
        auto socket = std::make_unique<Socket>(AddressFamily::INET, SocketType::STREAM, Protocol::IP_TCP);
        _s_bind(socket->get_handle(), port);
        _s_listen(socket->get_handle(), backlog);
        return socket;
    }

    void TcpServer::_s_bind(SOCKET socket, const uint16_t port)
    {
        const EndpointIPv4 endpoint = EndpointIPv4::s_get_any_endpoint(port);
        const sockaddr_in sockaddr = endpoint.get_sockaddr();
        if (SOCKET_ERROR == ::bind(socket, reinterpret_cast<const SOCKADDR*>(&sockaddr), sizeof(sockaddr)))
        {
            throw Exception(Status::TCPSERVER_BIND_BIND_FAILED, WSAGetLastError());
        }
    }

    void TcpServer::_s_listen(SOCKET socket, const uint32_t backlog)
    {
        if (SOCKET_ERROR == ::listen(socket, backlog))
        {
            throw Exception(Status::TCPSERVER_LISTEN_LISTEN_FAILED, WSAGetLastError());
        }
    }
}
