#pragma once

#include <vector>
#include <string>

using Buffer = std::vector<uint8_t>;

namespace BufferUtils
{
    template<typename T>
    Buffer container_to_buffer(const T& container)
    {
        uint64_t size = container.size() * sizeof(std::decay_t<T>::value_type);
        Buffer buffer(size);
        CopyMemory(buffer.data(), container.data(), size);
        return buffer;
    }
}
