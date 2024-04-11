#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <numeric>

int main() {

    std::vector<int> vec;
    const size_t size = 20; // Taille du vecteur
    // Remplissage du vecteur avec des nombres aléatoires entre 0 et 100
    srand(time(nullptr)); // Initialisation du générateur de nombres aléatoires
    for (size_t i = 0; i < size; ++i) {
        vec.push_back(rand() % 101); // Ajoute un nombre aléatoire entre 0 et 100
    }

    // Affichage des éléments du vecteur
    std::cout << "Le vecteur contient : ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Recherche d'un nombre
    int nombre;
    std::cout << "Entrez un nombre à rechercher : ";
    std::cin >> nombre;
    auto found = std::find(vec.begin(), vec.end(), nombre);
    if (found != vec.end()) {
        std::cout << "Le nombre est présent dans le vecteur." << std::endl;
    } else {
        std::cout << "Le nombre n'est pas présent dans le vecteur." << std::endl;
    }

    // Comptage des occurrences d'un nombre
    int count = std::count(vec.begin(), vec.end(), nombre);
    std::cout << "Le nombre " << nombre << " apparaît " << count << " fois dans le vecteur." << std::endl;

    // Tri du vecteur
    std::sort(vec.begin(), vec.end());
    std::cout << "Vecteur trié : ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Calcul de la somme des éléments du vecteur
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "La somme des éléments du vecteur est : " << sum << std::endl;

    return 0;
}