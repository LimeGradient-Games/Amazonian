#pragma once

#include <filesystem>
#include <string>
#include <fmt/format.h>

namespace fs = std::filesystem;

namespace AmazonianUtils {
    std::string getResourcePath() {
        return fmt::format("{}/resources", fs::current_path().string());
    }
}