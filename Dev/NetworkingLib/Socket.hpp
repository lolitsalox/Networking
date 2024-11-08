#pragma once

#include "pch.hpp"
#include "Endpoint.hpp"

namespace Network
{
    class Socket
    {
    public:
        Socket(const AddressFamily address_family = AddressFamily::INET, 
               const SocketType type = SocketType::STREAM, 
               const Protocol protocol = Protocol::IP_TCP);
        explicit Socket(SOCKET socket);
        explicit Socket(const EndpointIPv4 endpoint);
        virtual ~Socket();
        Socket(const Socket&) = delete;
        Socket& operator=(const Socket&) = delete;
        Socket(Socket&&) = delete;
        Socket& operator=(Socket&&) = delete;

        virtual void send(const Buffer& buffer);
        virtual Buffer receive();

        SOCKET get_handle() const { return m_socket; }

    private:
        static SOCKET _s_create_socket(const AddressFamily address_family = AddressFamily::INET,
                                       const SocketType type = SocketType::STREAM,
                                       const Protocol protocol = Protocol::IP_TCP);
        static SOCKET _s_connect(const EndpointIPv4& endpoint);

    private:
        SOCKET m_socket;
    };
    using SocketUPtr = std::unique_ptr<Socket>;
}
