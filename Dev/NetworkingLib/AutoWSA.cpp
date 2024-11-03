#include "pch.hpp"
#include "Common.hpp"
#include "AutoWSA.hpp"

namespace Network
{
    AutoWSAUPtr AutoWSA::g_instance = nullptr;

    AutoWSA::AutoWSA() :
        m_wsa_data(_s_initialize_wsa())
    {}

    AutoWSA::~AutoWSA()
    {
        try
        {
            std::ignore = WSACleanup();
        }
        catch (...) {}
    }

    void AutoWSA::s_initialize()
    {
        if (nullptr != g_instance)
        {
            throw Exception(Status::AUTOWSA_S_INITIALIZE_WSA_ALREADY_INITIALIZED);
        }

        g_instance = std::unique_ptr<AutoWSA>(new AutoWSA());
    }

    WSADATA AutoWSA::_s_initialize_wsa()
    {
        WSADATA wsa_data = { 0 };
        int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
        if (0 != result)
        {
            throw Exception(Status::AUTOWSA_S_INITIALIZE_WSA_WSASTARTUP_FAILED, WSAGetLastError());
        }
        return wsa_data;
    }
}
