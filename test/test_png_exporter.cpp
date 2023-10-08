#include <gtest/gtest.h>
#include "png_exporter.h"

TEST(TextPNGTest, CreatingFromChar) {
  std::vector<std::byte> bytes{
    std::byte{0b11010101},
    std::byte{0b11110101},
    std::byte{0b01000010},
    std::byte{0b11010110},
    std::byte{0b11010110},
    std::byte{0b01000110}
  };

  cv::Mat expected = cv::imread("../resources/1337.png", cv::IMREAD_GRAYSCALE);
  auto result = PNGExporter().exportData(bytes);

  ASSERT_EQ(expected.size().height, result.size().height);
  ASSERT_EQ(expected.size().width, result.size().width);

  for(auto i=0;i<expected.size().width;i++){
    EXPECT_EQ(expected.at<uchar>(0, i), result.at<uchar>(0, i));
  }
}
