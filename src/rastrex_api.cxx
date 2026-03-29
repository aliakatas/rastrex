#include "rastrex/rastrex_api.hpp"
 
#include "gdal.h"

#include <string>
 
namespace rastrex 
{
 
    std::string gdal_version()
    {
        return std::string(__FUNCTION__) + 
            std::string(": ") + 
            std::string(GDALVersionInfo("RELEASE_NAME"));
    }

} // namespace rastrex
