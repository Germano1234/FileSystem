#include "node.hpp"

Node::Node(const std::string& name, char type, Node* parent)
    : name(name), type(type), parent(parent) {}

Node::~Node() {
    for (auto child : children) {
        delete child;
    }
}

void Node::addChild(Node* child) {
    children.push_back(child);
    child->setParent(this);
}

void Node::addChild(const std::string& name, char type) {
    Node* newNode = new Node(name, type, this);
    children.push_back(newNode);
}

bool Node::removeChild(const std::string& name) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if ((*it)->name == name) {
            delete *it;
            children.erase(it);
            return true;
        }
    }
    return false;
}

void Node::setParent(Node* parent) {
    this->parent = parent;
}

void Node::setType(char type) {
    this->type = type;
}

void Node::setName(const std::string& name) {
    this->name = name;
}

Node* Node::getChild(const std::string& name) {
    for (auto child : children) {
        if (child->name == name) {
            return child;
        }
    }
    return nullptr;
}

std::vector<Node*> Node::getChildren() {
    return children;
}

Node* Node::getParent() {
    return parent;
}

char Node::getType() {
    return type;
}

std::string Node::getName() {
    return name;
}
