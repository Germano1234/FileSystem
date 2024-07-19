#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "node.hpp"
#include <string>

class FileSystem {
public:
    FileSystem();
    bool mkdir(const std::string& name);
    bool cd(const std::string& name);
    void ls() const;
    std::string pwd() const;
private:
    Node* root;
    Node* current;
};

#endif 
