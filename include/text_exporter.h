#pragma once

#include "exporter.h"

class TextExporter : Exporter<std::string> {
    public:
    std::string exportBytes(const std::vector<std::byte>& bytes) const override;
};