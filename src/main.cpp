#include <iostream>
#include <string.h>
#include "asset_id.h"

int main(){
    auto a=AssetID();

    std::cout<<a.getDigits()<<std::endl;
}