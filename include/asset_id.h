#pragma once

#include <string>
#include <vector>

class AssetID{
    std::string digits;
    std::string checksum;
    std::vector<unsigned char> segmentRepresentation;
    
    public:
    std::string getDigits() const;
};