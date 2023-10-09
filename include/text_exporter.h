#pragma once

#include "exporter.h"

class TextExporter : public Exporter<std::string> {
    public:
    std::string exportData(const std::vector<std::byte>& bytes) const override;
};