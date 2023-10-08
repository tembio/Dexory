#include "asset_id.h"
#include "digit.h"
#include <string>


#include <iostream>
#include <bitset>
#include <cstddef>

AssetID::AssetID(const std::string& digitsStr) {
    if(digitsStr.empty()){
        throw std::invalid_argument("empty asset ID");
    }

    if(digitsStr.size()!=4){
        throw std::invalid_argument("asset ID does not have 4 digits");
    }

    for(const auto digit: digitsStr){
      digits.emplace_back(Digit{digit});
    }
}

unsigned char AssetID::checksum() const{
    unsigned int digitsInt[4] = {
        digits[0].NumericValue(),
        digits[1].NumericValue(),
        digits[2].NumericValue(),
        digits[3].NumericValue()
    };

    return (digitsInt[0] + (10*digitsInt[1]) + (100*digitsInt[2]) + (1000*digitsInt[3])) % 97;
}

void AssetID::png(const std::ostream& out) const {
    std::vector<std::byte> pngBytes;
    auto checksumStr = std::to_string(checksum());

    for (const auto checksumChar : checksumStr){
        pngBytes.emplace_back(Digit(checksumChar).SevenSegmentBits());
    }
    for (const auto& digit : digits){
        pngBytes.emplace_back(digit.SevenSegmentBits());
    }

    for (auto b : pngBytes){
        std::cout<<std::bitset<8>(std::to_integer<int>(b))<<std::endl;
    }
    
}