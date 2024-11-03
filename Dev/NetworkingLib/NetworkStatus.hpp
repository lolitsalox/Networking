#pragma once

#include "pch.hpp"

namespace Network
{
    enum class Status : uint32_t
    {
        // AutoWSA
        AUTOWSA_S_INITIALIZE_WSA_ALREADY_INITIALIZED = 0,
        AUTOWSA_S_INITIALIZE_WSA_WSASTARTUP_FAILED,

        // EndpointIPv4
        ENDPOINTIPV4_S_GET_SOCKADDR_INETPTONW_FAILED,

        // Socket
        SOCKET_S_CREATE_SOCKET_WSASOCKETW_FAILED,
        SOCKET_BIND_BIND_FAILED,
        SOCKET_CONNECT_WSACONNECT_FAILED,
    };
}
