#include "filesystem.hpp"
#include <iostream>

FileSystem::FileSystem() {
    root = new Node("/", nullptr);
    current = root;
}

bool FileSystem::mkdir(const std::string& name) {
    return current->addChild(name);
}

bool FileSystem::cd(const std::string& name) {
    if (name == "..") {
        if (current->getParent() != nullptr) {
            current = current->getParent();
            return true;
        }
        else {
            return false;
        }
    }
    else {
        Node* child = current->getChild(name);
        if (child != nullptr) {
            current = child;
            return true;
        }
        else {
            return false;
        }
    }
}

void FileSystem::ls() const {
    current->listChildren();
}

std::string FileSystem::pwd() const {
    return current->getPath();
}

