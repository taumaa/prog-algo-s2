#ifndef NODE_HPP
#define NODE_HPP
#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    static Node* create_node(int value);
    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();
    void display_infixe() const;
    std::vector<Node const*> prefixe() const;
    static Node*& most_left(Node*& node) ;
    static bool remove(Node*& node, int value) ;
    static void delete_tree(Node* node) ;

};



#endif