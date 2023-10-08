#include <bitset>
#include <sstream>
#include "text_exporter.h"

std::string TextExporter::exportData(const std::vector<std::byte>& bytes) const {
    std::ostringstream os;
    for (auto b : bytes){
        os<<std::bitset<8>(std::to_integer<int>(b));
    }
    return os.str();
}