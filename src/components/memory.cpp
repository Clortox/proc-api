///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// memory functions implementation
//

#include "memory.hpp"

bool memory::getProcMem(crow::json::wvalue& ret){
    std::ifstream f (PROC_MEM_PATH);
    std::string line;
    if(f.is_open()){
        while(std::getline(f, line)){
            size_t colon = -1;
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

        f.close();
    } else {
        ret["message"] = "Failed to open proc filesystem";
        return false;
    }

    return true;
}

bool memory::getRawProcMem(std::string& ret){
    std::ifstream f (PROC_MEM_PATH);
    std::string line;
    if(f.is_open()){
        while(std::getline(f, line)){
            ret += line;
            ret += "\n";
        }
        f.close();
    } else {
        ret = "Failed to open proc filesystem";
        return false;
    }

    return true;
}

bool memory::getEasyMem(crow::json::wvalue& ret){
    std::ifstream f (PROC_MEM_PATH);
    std::string line;
    if(f.is_open()){
        for(int j = 0; j < 3; ++j){
            size_t colon = -1;
            int last_space = -1;
            int final_space = -1;
            std::getline(f, line);
            for(int i = 0; line[i] != '\0'; ++i){
                if(line[i] == ':')
                    colon = i;
                else if(last_space == -1 && line[i-1] == ' ' && line[i] != ' ')
                    last_space = i;
                else if(last_space != -1 && line[i] == ' ')
                    final_space = i;
            }

            ret[line.substr(0,colon)] = std::stof(line.substr(last_space, final_space - last_space));
        }
        f.close();
    } else {
        ret["message"] = "Failed to open proc filesystem";
        return false;
    }

    return true;
}
