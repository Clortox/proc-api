///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 29-4-22
// System functions definitions
//

#pragma once

#include <crow.h>

#include <string>
#include <fstream>

constexpr char PROC_UPTIME_PATH[] = "/proc/uptime";
constexpr char PROC_LOADAVG_PATH[] = "/proc/loadavg";
constexpr char PROC_HOSTNAME_PATH[] = "/proc/sys/kernel/hostname";

namespace state{
    bool getUptime(crow::json::wvalue&);
    bool getRawUptime(std::string&);
    bool getLoadAvg(crow::json::wvalue&);
    bool getRawLoadAvg(std::string&);
    bool getHostname(crow::json::wvalue&);
    bool getRawHostname(std::string&);
}
