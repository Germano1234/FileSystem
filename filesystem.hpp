#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "node.hpp"
#include <string>

class FileSystem {
private:
    Node* root;
    Node* currentDirectory;

    void addNode(Node* node);
    Node* findNode(const std::string& name);

public:
    FileSystem();
    ~FileSystem();

    std::string mkdir(const std::string& name);
    std::string touch(const std::string& name);
    std::string pwd();
    std::string ls();
    std::string rm(const std::string& name);
    std::string mv(const std::string& from, const std::string& to);
    std::string cd(const std::string& dirname);
};

#endif
