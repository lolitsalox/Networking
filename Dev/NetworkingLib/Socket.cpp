#include "pch.hpp"
#include "Common.hpp"
#include "Socket.hpp"

namespace Network
{
    Socket::Socket(const AddressFamily address_family, const SocketType type, const Protocol protocol) :
        m_socket(_s_create_socket(address_family, type, protocol))
    {}

    Socket::~Socket()
    {
        try
        {
            if (INVALID_SOCKET != m_socket)
            {
                ::closesocket(m_socket);
                m_socket = INVALID_SOCKET;
            }
        }
        catch (...) {}
    }

    SOCKET Socket::_s_create_socket(const AddressFamily address_family, const SocketType type, const Protocol protocol)
    {
        SOCKET socket = ::WSASocketW(static_cast<int>(address_family), 
                                     static_cast<int>(type), 
                                     static_cast<int>(protocol),
                                     nullptr,
                                     0,
                                     WSA_FLAG_OVERLAPPED);
        if (INVALID_SOCKET == socket)
        {
            throw Exception(Status::SOCKET_S_CREATE_SOCKET_WSASOCKETW_FAILED, WSAGetLastError());
        }
        return socket;
    }

    void Socket::bind(const EndpointIPv4& endpoint)
    {
        const sockaddr_in sockaddr = endpoint.get_sockaddr();
        if (SOCKET_ERROR == ::bind(m_socket, reinterpret_cast<const SOCKADDR*>(&sockaddr), sizeof(sockaddr)))
        {
            throw Exception(Status::SOCKET_BIND_BIND_FAILED, WSAGetLastError());
        }
    }

    void Socket::connect(const EndpointIPv4& endpoint)
    {
        const sockaddr_in sockaddr = endpoint.get_sockaddr();
        if (SOCKET_ERROR == ::WSAConnect(m_socket, 
                                         reinterpret_cast<const SOCKADDR*>(&sockaddr), 
                                         sizeof(sockaddr), 
                                         nullptr, nullptr, nullptr, nullptr))
        {
            throw Exception(Status::SOCKET_CONNECT_WSACONNECT_FAILED, WSAGetLastError());
        }
    }

    void Socket::send(const Buffer& buffer)
    {
        ::send(m_socket, reinterpret_cast<const char*>(buffer.data()), static_cast<int>(buffer.size()), 0);
    }
    
    Buffer Socket::receive()
    {
        Buffer buffer(1024);
        int bytes = ::recv(m_socket, reinterpret_cast<char*>(buffer.data()), static_cast<int>(buffer.size()), 0);
        buffer.resize(bytes);
        return buffer;
    }
}
