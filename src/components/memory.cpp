///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// memory functions implementation
//

#include "memory.hpp"

void memory::getProcMem(crow::json::wvalue& ret){
    std::ifstream f ("/proc/meminfo");
    std::string line;
    if(f.is_open()){
        while(std::getline(f, line)){
            size_t colon;
            int last_space = -1;
            for(int i = 0; line[i] != '\0' ; ++i){
                if(line[i] == ':')
                    colon = i;
                else if(line[i-1] == ' ' && line[i] != ' ' && last_space == -1)
                    last_space = i;
            }

            std::cerr << colon << " " << last_space << std::endl;

            ret[line.substr(0,colon)] = line.substr(last_space);
        }
    } else {
        ret["message"] = "Failed to open proc filesystem";
    }
}
