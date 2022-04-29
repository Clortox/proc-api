///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 29-4-22
// System functions implementation
//

#include "state.hpp"

bool state::getUptime(crow::json::wvalue& ret){
    std::ifstream f ("/proc/uptime");
    std::string line;
    if(f.is_open()){
        int space = -1;
        std::getline(f, line);

        for(int i = 0; line[i] != '\0'; ++i){
            if(line[i] == ' '){
                space = i;
                break;
            }
        }

        ret["uptime"] = std::stof(line.substr(0, space));
        ret["idle"] = std::stof(line.substr(space+1));

        f.close();

    } else {
        ret["message"] = "Failed to open proc filesystem";
        return false;
    }

    return true;
}

bool state::getRawUptime(std::string& ret){
    std::ifstream f ("/proc/uptime");
    if(f.is_open()){
        std::getline(f, ret);
        ret += "\n";
        f.close();
    } else {
        ret = "Failed to open proc filesystem";
        return false;
    }

    return true;
}
