///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// memory functions defintion
//

#pragma once

#include <crow.h>

#include <string>
#include <fstream>

constexpr char PROC_MEM_PATH[] = "/proc/meminfo";

namespace memory{
    bool getProcMem(crow::json::wvalue&);
    bool getRawProcMem(std::string&);
    bool getEasyMem(crow::json::wvalue&);
}
