#include <string>
#include <array>
#include "digit.h"

constexpr std::array<std::byte, 10> segmentRepresentation = {
    std::byte{0b01110111}, //0
    std::byte{0b01000010}, //1
    std::byte{0b10110110}, //2
    std::byte{0b11010110}, //3
    std::byte{0b11000011}, //4
    std::byte{0b11010101}, //5
    std::byte{0b11110101}, //6
    std::byte{0b01000110}, //7
    std::byte{0b11110111}, //8
    std::byte{0b11010111}  //9
};

Digit::Digit(const char d){
    if(!std::isdigit(d)){
        throw std::invalid_argument("non numeric digit value");
    }
    value = d;
    numericValue = value-'0';
}

std::byte Digit::SevenSegmentBits() const{
    return segmentRepresentation[numericValue];
}

unsigned char Digit::NumericValue() const{
    return numericValue;
}