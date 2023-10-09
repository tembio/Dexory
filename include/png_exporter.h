#pragma once

#include <string>
#include "exporter.h"
#include <opencv2/opencv.hpp>

class PNGExporter : public Exporter<cv::Mat> {
    public:
    cv::Mat exportData(const std::vector<std::byte>& bytes) const override;
};