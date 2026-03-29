// #include <gtest/gtest.h>
#include "rastrex/rastrex_api.hpp"

#include <cstdlib>
#include <iostream>
#include <filesystem>

// TEST(GdalVersion, ReturnsNonEmptyString)
// {
//     const auto version = rastrex::rastrex_version();
//     EXPECT_FALSE(version.empty());
// }

int main(int argc, char* argv[])
{
    std::cout << "Starting " << std::filesystem::path(argv[0]).stem().string() << "..." << std::endl;

    std::cout << "  Version: " << rastrex::gdal_version() << std::endl;

    std::cout << "\nDone" << std::endl;
    return EXIT_SUCCESS;
}