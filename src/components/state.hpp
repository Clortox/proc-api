///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 29-4-22
// System functions definitions
//

#pragma once

#include <crow.h>

#include <string>
#include <fstream>

namespace state{
    bool getUptime(crow::json::wvalue&);
    bool getRawUptime(std::string&);
}
