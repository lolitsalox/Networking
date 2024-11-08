#pragma once

#include "pch.hpp"

namespace Network
{
    class EndpointIPv4
    {
    public:
        EndpointIPv4(const std::wstring& ip_address, const uint16_t port);
        virtual ~EndpointIPv4() = default;
        EndpointIPv4(const EndpointIPv4&) = default;
        EndpointIPv4& operator=(const EndpointIPv4&) = default;
        EndpointIPv4(EndpointIPv4&&) = default;
        EndpointIPv4& operator=(EndpointIPv4&&) = default;

        const sockaddr_in get_sockaddr() const { return m_sockaddr; };

        static EndpointIPv4 s_get_loopback_endpoint(const uint16_t port);
        static EndpointIPv4 s_get_any_endpoint(const uint16_t port);

    private:
        EndpointIPv4(const sockaddr_in sockaddr);
        static EndpointIPv4 _s_get_endpoint(const uint16_t port, const uint32_t endpoint);
        static sockaddr_in _s_get_sockaddr(const std::wstring& ip_address, const uint16_t port);

    private:
        const sockaddr_in m_sockaddr;
    };
}
