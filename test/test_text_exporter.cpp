#include <gtest/gtest.h>
#include "text_exporter.h"

TEST(TextExporterTest, CreatingFromChar) {
  std::vector<std::byte> bytes{
    std::byte{0b11010101},
    std::byte{0b11110101},
    std::byte{0b01000010},
    std::byte{0b11010110},
    std::byte{0b11010110},
    std::byte{0b01000110}
  };

  TextExporter t;
  EXPECT_EQ("110101011111010101000010110101101101011001000110", t.exportBytes(bytes));
}
