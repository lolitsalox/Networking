#pragma once

#include "pch.hpp"
#include "NetworkStatus.hpp"

namespace Network
{
    class Exception : public std::system_error
    {
    public:
        Exception(const Status status, const uint32_t additional_info = 0) :
            std::system_error(additional_info, std::system_category(), _s_create_message(status)),
            m_status(status),
            m_addtional_info(additional_info)
        {}
        virtual ~Exception() = default;
        Exception(const Exception&) = default;
        Exception& operator=(const Exception&) = default;
        Exception(Exception&&) = default;
        Exception& operator=(Exception&&) = default;

        inline Status get_status() const { return m_status; }
        inline uint32_t get_addtional_info() const { return m_addtional_info; }

    private:
        inline static std::string _s_create_message(const Status status)
        {
            return "Status: " + std::to_string(static_cast<uint32_t>(status));
        }

    private:
        const Status m_status;
        const uint32_t m_addtional_info;
    };
}
