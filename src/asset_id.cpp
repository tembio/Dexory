#include "asset_id.h"
#include "digit.h"

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

    strValue = digitsStr;
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
