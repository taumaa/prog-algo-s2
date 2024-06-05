#include <iostream>
#include <vector>
#include <numeric>
#include "node.hpp"



int main() {

    // Création de l'arbe
    Node* root = Node::create_node(5);
    int values[] = {3, 7, 2, 4, 6, 8, 1, 9, 0};

    for (int value : values) {
        root->insert(value);
    }

    // valeurs des nœuds de l'arbre binaire dans l'ordre infixe
    std::cout << "Affichage infixe: ";
    root->display_infixe();
    std::cout << std::endl;

    // valeur minimale et maximale de l'arbre
    Node* min_node = root;
    while (min_node->left != nullptr) {
        min_node = min_node->left;
    }
    std::cout << "Valeur minimale: " << min_node->value << std::endl;

    Node* max_node = root;
    while (max_node->right != nullptr) {
        max_node = max_node->right;
    }
    std::cout << "Valeur maximale: " << max_node->value << std::endl;

    // somme des valeurs des nœuds de l'arbre binaire (prefixe)
    std::vector<Node const*> prefix_nodes = root->prefixe();
    int sum = std::accumulate(prefix_nodes.begin(), prefix_nodes.end(), 0, [](int acc, Node const* node) {
        return acc + node->value;
    });
    std::cout << "Somme des valeurs (préfixe): " << sum << std::endl;

    // hauteur de l'arbre binaire
    std::cout << "Hauteur de l'arbre: " << root->height() << std::endl;

    // Supprimer
    Node::delete_tree(root);

    return 0;
}