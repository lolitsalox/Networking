#include "pch.hpp"
#include "Common.hpp"
#include "Endpoint.hpp"

namespace Network
{
    EndpointIPv4::EndpointIPv4(const std::wstring& ip_address, const uint16_t port) :
        m_sockaddr(_s_get_sockaddr(ip_address, port))
    {}

    EndpointIPv4::EndpointIPv4(const sockaddr_in sockaddr) :
        m_sockaddr(sockaddr)
    {}

    EndpointIPv4 EndpointIPv4::_s_get_endpoint(const uint16_t port, const uint32_t endpoint)
    {
        sockaddr_in service = { 0 };
        service.sin_family = static_cast<int>(AddressFamily::INET);
        service.sin_addr.s_addr = ::htonl(endpoint);
        service.sin_port = ::htons(port);
        return EndpointIPv4(service);
    }

    EndpointIPv4 EndpointIPv4::s_get_loopback_endpoint(const uint16_t port)
    {
        return _s_get_endpoint(port, INADDR_LOOPBACK);
    }

    EndpointIPv4 EndpointIPv4::s_get_any_endpoint(const uint16_t port)
    {
        return _s_get_endpoint(port, INADDR_ANY);
    }

    sockaddr_in EndpointIPv4::_s_get_sockaddr(const std::wstring& ip_address, const uint16_t port)
    {
        sockaddr_in service = { 0 };
        service.sin_family = static_cast<int>(AddressFamily::INET);
        service.sin_port = htons(port);
        if (1 != InetPtonW(service.sin_family, ip_address.c_str(), &service.sin_addr.s_addr))
        {
            throw Exception(Status::ENDPOINTIPV4_S_GET_SOCKADDR_INETPTONW_FAILED, WSAGetLastError());
        }
        return service;
    }
}
