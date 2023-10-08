#include <gtest/gtest.h>
#include "digit.h"
#include <unordered_map>

TEST(DigitTest, CreatingFromChar) {
    Digit('1');
}

TEST(DigitTest, CreatingFromCharFailsIfNotNumeric) {
    EXPECT_THROW({
        try{
            Digit('a');
        }
        catch(const std::invalid_argument& e){
            EXPECT_STREQ( "non numeric digit value", e.what() );
            throw;
        }
    }, std::invalid_argument );
}

TEST(DigitTest, CreatingSevenSegmentBits) {
    std::unordered_map<unsigned char,std::byte> testCases = {
        {'0',std::byte{0b01110111}},
        {'1',std::byte{0b01000010}},
        {'2',std::byte{0b10110110}},
        {'3',std::byte{0b11010110}},
        {'4',std::byte{0b11000011}},
        {'5',std::byte{0b11010101}},
        {'6',std::byte{0b11110101}},
        {'7',std::byte{0b01000110}},
        {'8',std::byte{0b11110111}},
        {'9',std::byte{0b11010111}}
    };

    for(auto const& [digit, expected] : testCases){
        EXPECT_EQ(expected, Digit(digit).SevenSegmentBits());
    }
}

TEST(DigitTest, GetNumericValue) {
    std::unordered_map<unsigned char,unsigned char> testCases = {
        {'0',0},
        {'1',1},
        {'2',2},
        {'3',3},
        {'4',4},
        {'5',5},
        {'6',6},
        {'7',7},
        {'8',8},
        {'9',9}
    };

    for(auto const& [digit, expected] : testCases){
        EXPECT_EQ(expected, Digit(digit).NumericValue());
    }
}