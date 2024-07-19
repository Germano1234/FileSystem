#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Node {
public:
    Node(const std::string& name, Node* parent);
    bool addChild(const std::string& name);
    Node* getChild(const std::string& name) const;
    Node* getParent() const;
    void listChildren() const;
    std::string getPath() const;
private:
    std::string name;
    Node* parent;
    std::unordered_map<std::string, Node*> children;
};

#endif 
