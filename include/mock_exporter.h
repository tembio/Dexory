#pragma once

#include <gmock/gmock.h>
#include "exporter.h"

template<typename T>
class MockExporter : public Exporter<T> {
 public:
 MOCK_METHOD(T, exportData, (const std::vector<std::byte>& bytes), (override, const));
};