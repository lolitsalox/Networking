#pragma once

#include <tuple>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <system_error>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinSock2.h>
#include <ws2tcpip.h>

#include "NetworkUtils.hpp"
#include "BufferUtils.hpp"