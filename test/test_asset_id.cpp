#include <gtest/gtest.h>
#include "asset_id.h"
#include <string>


TEST(AssetIDTest, CreatingAssetIDWithNumericalDigitsSucceeds) {
  AssetID("123");
}

TEST(AssetID, CreatingAssetIDWithEmptyDigitsThrowsException) {
  
  EXPECT_THROW({
        try{
            AssetID("");
        }
        catch(const std::invalid_argument& e){
            EXPECT_STREQ( "empty digit value", e.what() );
            throw;
        }
    }, std::invalid_argument );
}

TEST(AssetID, CreatingAssetIDWithNonNumericalDigitsThrowsException) {
  
  EXPECT_THROW({
        try{
            AssetID("1a");
        }
        catch(const std::invalid_argument& e){
            EXPECT_STREQ( "non numeric digit value", e.what() );
            throw;
        }
    }, std::invalid_argument );
}
