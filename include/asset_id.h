#pragma once

#include <string>
#include <vector>

class AssetID{
    std::string digits;
    std::string checksum;
    std::vector<unsigned char> segmentRepresentation;
    
    public:
    AssetID(const std::string& digits);

    private:
    bool is_number(const std::string& s);
};