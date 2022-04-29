///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// parseopt implementation
//

#include "parseopt.hpp"

void help(char* progName){
    std::cout << "Usage: " << progName << " [FLAGS]\n";
    std::cout << "Options:\n";
    std::cout << " [-p PORT]     Port to listen on (Default 5000)\n";
    std::cout << " [-n NAME]     Server name (Default \"proc-api\")\n";
    std::cout << " [-a PATH]     Path to file containing authorization tokens\n";
    std::cout << "               If the -a flag is not passed, no authorization is used\n";
    std::cout << " [-h]          Display this help message\n\n";
    exit(1);
}

option_flags* parse_options(int argc, char** argv){
    char c;

    option_flags* ret = new option_flags;

    ret->port = 5000;
    ret->name = "proc-api";
    ret->auth_path = "";

    while((c = getopt(argc, argv, optarg_string)) != -1){
        switch(c){
            case 'p':
                ret->port = atoi(optarg);
                break;
            case 'n':
                ret->name = std::string(optarg);
                break;
            case 'a':
                ret->auth_path = std::string(optarg);
                break;
            case '?':
                std::cerr << "Unkown option: " << (char)optopt << "\n";
            case 'h':
                help(argv[0]);
                break;
            default:
                abort();
        }
    }

    return ret;
}
