#pragma once
#include <cstddef>

class Digit{
    unsigned char value;
    unsigned int numericValue;

    public:
    Digit(const char d);
    std::byte SevenSegmentBits() const;
    unsigned char NumericValue() const;
};