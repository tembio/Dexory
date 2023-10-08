#include <gtest/gtest.h>
#include "asset_id.h"
#include <string>


TEST(AssetIDTest, CreatingAssetIDWithNumericalDigits) {
  AssetID("123");
}

TEST(AssetID, CreatingAssetIDWithEmptyDigitsThrowsException) {
  EXPECT_THROW({
        try{
            AssetID("");
        }
        catch(const std::invalid_argument& e){
            EXPECT_STREQ( "empty asset ID", e.what() );
            throw;
        }
    }, std::invalid_argument );
}

TEST(AssetID, CreatingAssetIDWithIncorrectNumberOfDigitsThrowsException) {
  for(auto testCase : {"1","12345"}){
    EXPECT_THROW({
          try{
              AssetID{testCase};
          }
          catch(const std::invalid_argument& e){
              EXPECT_STREQ( "asset ID does not have 4 digits", e.what() );
              throw;
          }
      }, std::invalid_argument );
  }
}

TEST(AssetID, CreatingAssetIDWithNonNumericalDigitsThrowsException) {
  EXPECT_THROW({
        try{
            AssetID("1a12");
        }
        catch(const std::invalid_argument& e){
            EXPECT_STREQ( "non numeric digit value", e.what() );
            throw;
        }
    }, std::invalid_argument );
}

TEST(AssetID, checksum) {
  EXPECT_EQ(56, AssetID("1337").checksum());
}

TEST(AssetID, pngCreatesCorrectPNGFile) {
  AssetID("1337").png(std::cout);
  EXPECT_EQ(1,2);
  Hacer que PNG sea una clase exporter?? o solo metodo?



}
