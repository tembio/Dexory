#pragma once

#include <iostream>
#include "digit.h"
#include "exporter.h"

class AssetID{
    std::vector<Digit> digits;
    
    public:
    AssetID(const std::string& digitsStr);
    unsigned char checksum() const;
    
    template<typename T>
    T exportID(const Exporter<T>* exporter) const {
        std::vector<std::byte> bytes;
        auto checksumStr = std::to_string(checksum());

        for (const auto checksumChar : checksumStr){
            bytes.emplace_back(Digit(checksumChar).SevenSegmentBits());
        }
        for (const auto& digit : digits){
            bytes.emplace_back(digit.SevenSegmentBits());
        }

        // for (auto b : pngBytes){
        //     std::cout<<std::bitset<8>(std::to_integer<int>(b))<<std::endl;
        // }
        return exporter->exportBytes(bytes);
    }
};