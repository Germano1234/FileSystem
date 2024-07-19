#include "terminal.hpp"
#include <iostream>
#include <string>
#include <sstream>

Terminal::Terminal() {}

void Terminal::run() {
    std::string command;
    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, command);

        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "mkdir") {
            std::string name;
            iss >> name;
            std::cout << fs.mkdir(name) << std::endl;
        } else if (cmd == "touch") {
            std::string name;
            iss >> name;
            std::cout << fs.touch(name) << std::endl;
        } else if (cmd == "pwd") {
            std::cout << fs.pwd() << std::endl;
        } else if (cmd == "ls") {
            std::cout << fs.ls() << std::endl;
        } else if (cmd == "rm") {
            std::string name;
            iss >> name;
            std::cout << fs.rm(name) << std::endl;
        } else if (cmd == "mv") {
            std::string from, to;
            iss >> from >> to;
            std::cout << fs.mv(from, to) << std::endl;
        } else if (cmd == "cd") {
            std::string dirname;
            iss >> dirname;
            std::cout << fs.cd(dirname) << std::endl;
        } else if (cmd == "exit") {
            break;
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}
