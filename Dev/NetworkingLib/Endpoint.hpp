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

    private:
        static sockaddr_in _s_get_sockaddr(const std::wstring& ip_address, const uint16_t port);

    private:
        const sockaddr_in m_sockaddr;
    };
}
