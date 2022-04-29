///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// memory functions defintion
//

#pragma once

#include <crow.h>

#include <string>
#include <fstream>

namespace memory{
    void getProcMem(crow::json::wvalue&);
    void getEasyMem(crow::json::wvalue&);
}
