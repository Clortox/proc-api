///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// memory functions implementation
//

#include "memory.hpp"

bool memory::getProcMem(crow::json::wvalue& ret){
    std::ifstream f ("/proc/meminfo");
    std::string line;
    if(f.is_open()){
        while(std::getline(f, line)){
            size_t colon;
            int last_space = -1;
            int final_space = -1;
            for(int i = 0; line[i] != '\0' ; ++i){
                if(line[i] == ':')
                    colon = i;
                else if(last_space == -1 && line[i-1] == ' ' && line[i] != ' ' )
                    last_space = i;
                else if(last_space != -1 && line[i] == ' ')
                    final_space = i;
            }

            ret[line.substr(0,colon)] = std::stof(line.substr(last_space, final_space - last_space));
        }
    } else {
        ret["message"] = "Failed to open proc filesystem";
        return false;
    }

    return true;
}

bool memory::getRawProcMem(std::string& ret){
    std::ifstream f ("/proc/meminfo");
    std::string line;
    if(f.is_open()){
        while(std::getline(f, line)){
            ret += line;
            ret += "\n";
        }
    } else {
        ret = "Failed to open proc filesystem";
        return false;
    }

    return true;
}
