#pragma once

#include "pch.hpp"

namespace Network
{
    class AutoWSA;
    using AutoWSAUPtr = std::unique_ptr<AutoWSA>;

    class AutoWSA
    {
    public:
        virtual ~AutoWSA();
        AutoWSA(const AutoWSA&) = delete;
        AutoWSA& operator=(const AutoWSA&) = delete;
        AutoWSA(AutoWSA&&) = delete;
        AutoWSA& operator=(AutoWSA&&) = delete;
    
        static void s_initialize();

    private:
        AutoWSA();
        static WSADATA _s_initialize_wsa();

    private:
        static AutoWSAUPtr g_instance;
        const WSADATA m_wsa_data;
    };
}
