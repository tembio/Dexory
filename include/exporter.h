#pragma once

#include <vector>
#include <cstddef>

template<typename T>
class Exporter{
    public:
    virtual T exportBytes(const std::vector<std::byte>& bytes) const = 0;
};
