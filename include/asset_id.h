#pragma once

#include <vector>
#include <iostream>
#include "digit.h"

class AssetID{
    std::vector<Digit> digits;
    
    public:
    AssetID(const std::string& digitsStr);
    unsigned char checksum() const;
    void png(const std::ostream& out) const;
};