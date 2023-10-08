#pragma once

#include <vector>
#include <cstddef>

template<typename T>
class Exporter{
    public:
    virtual T exportData(const std::vector<std::byte>& bytes) const = 0;
};
