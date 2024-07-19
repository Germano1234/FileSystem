#include "terminal.hpp"
#include <iostream>
#include <sstream>

void Terminal::run() {
    std::string command;
    while (true) {
        std::cout << fs.pwd() << "> ";
        if (!std::getline(std::cin, command)) {
            break;
        }
        executeCommand(command);
    }
}

void Terminal::executeCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;
    if (cmd == "mkdir") {
        std::string dirname;
        iss >> dirname;
        if (fs.mkdir(dirname)) {
            std::cout << "directory " << dirname << " created successfully" << std::endl;
        }
        else {
            std::cout << "failed to create directory " << dirname << std::endl;
        }
    }
    else if (cmd == "cd") {
        std::string dirname;
        iss >> dirname;
        if (!fs.cd(dirname)) {
            std::cout << "failed to change directory to " << dirname << std::endl;
        }
    }
    else if (cmd == "ls") {
        fs.ls();
    }
}

