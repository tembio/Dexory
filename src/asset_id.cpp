#include "asset_id.h"

AssetID::AssetID(const std::string& digits) : digits(digits) {
    if(digits == ""){
        throw std::invalid_argument("empty digit value");
    }
    if(!is_number(digits)){
        throw std::invalid_argument("non numeric digit value");
    }
}


inline bool AssetID::is_number(const std::string& s)
{
    return std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}