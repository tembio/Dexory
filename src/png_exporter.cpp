#include <bitset>
#include <sstream>
#include "png_exporter.h"

cv::Mat PNGExporter::exportData(const std::vector<std::byte>& bytes) const {
    cv::Mat image(1, 256, CV_8UC1);
    image = cv::Scalar(255);

    auto columnIndex = 8;
    for (const auto& byte : bytes){
        auto bits = std::bitset<8>(std::to_integer<int>(byte));
        
        for(auto i=7;i>=0;i--){ //correct endianess
            image.at<uchar>(0,columnIndex++) = bits[i]==1? 0 : 255; 
        }
    }

    return image;
}