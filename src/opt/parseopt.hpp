///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// parseopt definitions
//

#pragma once

#include <getopt.h>
#include <iostream>

///////////////////////////////////////
// cli options

constexpr char optarg_string[] = "p:h";

struct option_flags {
    uint16_t port;
};

void help(char*);
option_flags* parse_options(int, char**);
