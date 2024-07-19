#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "filesystem.hpp"
#include <string>

class Terminal {
public:
    void run();
private:
    FileSystem fs;
    void executeCommand(const std::string& command);
};

#endif 
