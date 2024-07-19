#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "filesystem.hpp"
#include <string>

class Terminal {
private:
    FileSystem fs;

public:
    Terminal();
    void run();
};

#endif
