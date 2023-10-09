#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock_exporter.h"
#include "asset_id.h"

TEST(AssetIDTest, CreatingAssetIDWithNumericalDigits) {
  AssetID("1234");
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

TEST(AssetID, str) {
  auto assetID = AssetID("1337");
  EXPECT_EQ("1337", assetID.str());
}

TEST(AssetID, checksum) {
  EXPECT_EQ(56, AssetID("1337").checksum());
}

TEST(AssetID, exportIDCallExporterWithCorrectBytes) {
  MockExporter<int> exporter;
  std::vector<std::byte> expectedBytes{
    std::byte{0b11010101},
    std::byte{0b11110101},
    std::byte{0b01000010},
    std::byte{0b11010110},
    std::byte{0b11010110},
    std::byte{0b01000110}
  };

  EXPECT_CALL(exporter, exportData(expectedBytes));

  AssetID("1337").exportID(&exporter);
}
