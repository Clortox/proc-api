///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Routes definition
//

#pragma once

#include <string>
#include <algorithm>

#include <crow.h>
#include "components/memory.hpp"
#include "components/state.hpp"

#include "auth/auth.hpp"

void setRoutes(crow::SimpleApp&);
