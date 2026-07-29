#pragma once

#include <cstdint>

namespace nn::mem {

class StandardAllocator {
public:
    void* Allocate(std::uint64_t size);
    void* Allocate(std::uint64_t size, std::uint64_t alignment);
    void Free(void* ptr);
};

}  // namespace nn::mem
