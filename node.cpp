#include "node.hpp"
#include <iostream>

Node::Node(const std::string& name, Node* parent) : name(name), parent(parent) {}

bool Node::addChild(const std::string& name) {
    if (children.find(name) == children.end()) {
        children[name] = new Node(name, this);
        return true;
    }
    return false;
}

Node* Node::getChild(const std::string& name) const {
    auto it = children.find(name);
    if (it != children.end()) {
        return it->second;
    }
    return nullptr;
}

Node* Node::getParent() const {
    return parent;
}

void Node::listChildren() const {
    for (const auto& child : children) {
        std::cout << "d " << child.first << std::endl;
    }
}

std::string Node::getPath() const {
    if (parent == nullptr) {
        return "root";
    }
    return parent->getPath() + "/" + name;
}

