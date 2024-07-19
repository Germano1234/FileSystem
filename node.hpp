#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

class Node {
private:
    std::string name;
    char type; // 'f' for file, 'd' for directory
    Node* parent;
    std::vector<Node*> children;

public:
    Node(const std::string& name = "", char type = ' ', Node* parent = nullptr);
    ~Node();

    void addChild(Node* child);
    void addChild(const std::string& name, char type);
    bool removeChild(const std::string& name);
    void setParent(Node* parent);
    void setType(char type);
    void setName(const std::string& name);
    Node* getChild(const std::string& name);
    std::vector<Node*> getChildren();
    Node* getParent();
    char getType();
    std::string getName();
};

#endif
