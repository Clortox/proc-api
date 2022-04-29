///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 29-4-22
// System functions definitions
//

#pragma once

#include <crow.h>

#include <string>
#include <fstream>

constexpr char procuptimepath[] = "/proc/uptime";
constexpr char procloadavgpath[] = "/proc/loadavg";

namespace state{
    bool getUptime(crow::json::wvalue&);
    bool getRawUptime(std::string&);
    bool getLoadAvg(crow::json::wvalue&);
    bool getRawLoadAvg(std::string&);
}
