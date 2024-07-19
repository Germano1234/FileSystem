#include "filesystem.hpp"
#include <iostream>
#include <sstream>

FileSystem::FileSystem() {
    root = new Node("/root", 'd', nullptr);
    currentDirectory = root;
}

FileSystem::~FileSystem() {
    delete root;
}

void FileSystem::addNode(Node* node) {
    currentDirectory->addChild(node);
}

Node* FileSystem::findNode(const std::string& name) {
    for (auto child : currentDirectory->getChildren()) {
        if (child->getName() == name) {
            return child;
        }
    }
    return nullptr;
}

std::string FileSystem::mkdir(const std::string& name) {
    if (findNode(name)) {
        return "Error: " + name + " exists";
    }
    addNode(new Node(name, 'd', currentDirectory));
    return "directory " + name + " created successfully";
}

std::string FileSystem::touch(const std::string& name) {
    if (findNode(name)) {
        return "Error: " + name + " exists";
    }
    addNode(new Node(name, 'f', currentDirectory));
    return "file " + name + " created successfully";
}

std::string FileSystem::pwd() {
    std::stringstream ss;
    Node* temp = currentDirectory;
    while (temp != nullptr) {
        ss << "" << temp->getName();
        temp = temp->getParent();
    }
    return ss.str();
}


std::string FileSystem::ls() {
    std::stringstream ss;
    for (auto child : currentDirectory->getChildren()) {
        ss << child->getType() << " " << child->getName() << "\n";
    }
    return ss.str();
}

std::string FileSystem::rm(const std::string& name) {
    Node* nodeToRemove = findNode(name);
    if (!nodeToRemove) {
        return "No such file or directory";
    }
    if (nodeToRemove->getType() == 'd') {
        // Remove directory recursively
        delete nodeToRemove;
    } else {
        // Remove file
        currentDirectory->removeChild(name);
    }
    return name + " removed successfully";
}

std::string FileSystem::mv(const std::string& from, const std::string& to) {
    Node* sourceNode = findNode(from);
    if (!sourceNode) {
        return "file/directory not found";
    }
    if (findNode(to)) {
        return "Error: " + to + " exists";
    }
    sourceNode->setName(to);
    return "file/dir renamed successfully";
}

std::string FileSystem::cd(const std::string& dirname) {
    if (dirname == "..") {
        if (currentDirectory != root) {
            currentDirectory = currentDirectory->getParent();
        }
    } else {
        Node* node = findNode(dirname);
        if (node && node->getType() == 'd') {
            currentDirectory = node;
        } else {
            return "Error: " + dirname + " not found or is not a directory";
        }
    }
    return pwd();
}
