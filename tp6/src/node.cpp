#include "node.hpp"
#include <iostream>

Node* Node::create_node(int value) {
    Node* node = new Node;
    node->value = value;
    return node;
}

bool Node::is_leaf() const {
    return left == nullptr && right == nullptr;
}

void Node::insert(int value) {
    if (value < this->value) {
        if (left == nullptr) {
            left = create_node(value);
        } else {
            left->insert(value);
        }
    } else {
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

int Node::height() const {
    int left_height = left == nullptr ? 0 : left->height();
    int right_height = right == nullptr ? 0 : right->height();
    return 1 + std::max(left_height, right_height);
}

void Node::delete_childs() {
    if (left != nullptr) {
        left->delete_childs();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->delete_childs();
        delete right;
        right = nullptr;
    }
}

void Node::display_infixe() const {
    if (left != nullptr) {
        left->display_infixe();
    }
    std::cout << value << " ";
    if (right != nullptr) {
        right->display_infixe();
    }
}

std::vector<Node const*> Node::prefixe() const {
    std::vector<Node const*> result;
    result.push_back(this);
    if (left != nullptr) {
        std::vector<Node const*> left_prefix = left->prefixe();
        result.insert(result.end(), left_prefix.begin(), left_prefix.end());
    }
    if (right != nullptr) {
        std::vector<Node const*> right_prefix = right->prefixe();
        result.insert(result.end(), right_prefix.begin(), right_prefix.end());
    }
    return result;
}

Node*& Node::most_left(Node*& node) {
    if (node->left == nullptr) {
        return node;
    }
    return most_left(node->left);
}


bool Node::remove(Node*& node, int value) {
    if (node == nullptr) {
        return false; // La valeur n'a pas été trouvée
    }

    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        // Cas où le nœud à supprimer est trouvé
        if (node->left == nullptr && node->right == nullptr) {
            // Le nœud est une feuille
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            // Le nœud a un seul enfant à droit
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            // Le nœud a un seul enfant à gauche
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            // Le nœud a deux enfants
            Node* successor = node->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            node->value = successor->value;
            // Supprimer le successeur
            remove(node->right, successor->value);
        }
        return true;
    }
}

void Node::delete_tree(Node* node) {
    if (node != nullptr) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

