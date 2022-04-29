///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 29-4-22
// System functions implementation
//

#include "state.hpp"

bool state::getUptime(crow::json::wvalue& ret){
    std::ifstream f (procuptimepath);
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
    std::ifstream f (procuptimepath);
    if(f.is_open()){
        std::getline(f, ret);
        ret += '\n';
        f.close();
    } else {
        ret = "Failed to open proc filesystem";
        return false;
    }

    return true;
}

bool state::getLoadAvg(crow::json::wvalue& ret){
    std::ifstream f (procloadavgpath);
    std::string line;
    if(f.is_open()){
        int spaces[4];
        int ind = 0;
        std::getline(f, line);

        for(int i = 0; line[i] != '\0'; ++i){
            if(line[i] == ' '){
                spaces[ind] = i;
                ++ind;
            }
        }

        ret["1"] = std::stof(line.substr(0,spaces[0]));
        ret["5"] = std::stof(line.substr(spaces[0] + 1, spaces[1] - spaces[0]));
        ret["10"] = std::stof(line.substr(spaces[1] + 1, spaces[2] - spaces[1]));
        ret["processes"] = line.substr(spaces[2] + 1, spaces[3] - spaces[2] - 1);
        ret["lastPID"] = std::stoi(line.substr(spaces[3] + 1));

        f.close();
    } else {
        ret["message"] = "Failed to open proc filesystem";
        return false;
    }

    return true;
}

bool state::getRawLoadAvg(std::string& ret){
    std::ifstream f (procloadavgpath);
    if(f.is_open()){
        std::getline(f, ret);
        ret += '\n';
        f.close();
    } else {
        ret = "Failed to open proc filesystem";
        return false;
    }

    return true;
}
