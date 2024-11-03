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
        virtual ~Socket();
        Socket(const Socket&) = delete;
        Socket& operator=(const Socket&) = delete;
        Socket(Socket&&) = delete;
        Socket& operator=(Socket&&) = delete;

        virtual void bind(const EndpointIPv4& endpoint);
        virtual void connect(const EndpointIPv4& endpoint);
        virtual void send(const Buffer& buffer);
        virtual Buffer receive();

    private:
        static SOCKET _s_create_socket(const AddressFamily address_family, const SocketType type, const Protocol protocol);

    private:
        SOCKET m_socket;
    };
    using SocketUPtr = std::unique_ptr<Socket>;
}
