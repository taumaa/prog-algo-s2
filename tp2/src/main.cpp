#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"



bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

/*
 * Tri à bulles
 */


void selection_sort(std::vector<int> & vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(vec[i], vec[min_index]);
        }
    }
}

/*
 * Tri fusion
 */
void merge_sort_merge(std::vector<int> &vec, size_t left, size_t middle, size_t right) {
    std::vector<int> left_half(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> right_half(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t left_index = 0, right_index = 0, merge_index = left;

    while (left_index < left_half.size() && right_index < right_half.size()) {
        if (left_half[left_index] <= right_half[right_index]) {
            vec[merge_index++] = left_half[left_index++];
        } else {
            vec[merge_index++] = right_half[right_index++];
        }
    }

    while (left_index < left_half.size()) {
        vec[merge_index++] = left_half[left_index++];
    }

    while (right_index < right_half.size()) {
        vec[merge_index++] = right_half[right_index++];
    }
}

void merge_sort(std::vector<int> &vec, size_t left, size_t right) {
    if (right <= left) return; // Correction pour éviter une boucle infinie

    size_t middle = left + (right - left) / 2;
    merge_sort(vec, left, middle); // Récursion sur la première moitié

    merge_sort(vec, middle + 1, right); // Récursion sur la deuxième moitié

    merge_sort_merge(vec, left, middle, right); // Fusion des deux moitiés
}

void merge_sort(std::vector<int> &vec) {
    if (vec.size() <= 1) return; // On ne trie pas si le vecteur a 1 élément ou moins
    merge_sort(vec, 0, vec.size() - 1);
}


/*
 * Search
 */

int search(std::vector<int> &vec, int to_search) {
    size_t left = 0;
    size_t right = vec.size() - 1;

    while (left <= right) {
        size_t middle = left + (right - left) / 2;

        if (vec[middle] == to_search) {
            return middle; // Retourne l'indice de l'élément trouvé
        }

        if (vec[middle] < to_search) {
            left = middle + 1; // Recherche dans la moitié droite
        } else {
            right = middle - 1; // Recherche dans la moitié gauche
        }
    }

    return -1; // Élément non trouvé
}


int main() {

    std::vector<int> tab = generate_random_vector(5000) ;

    {
        ScopedTimer timer("Tri a bulle");
        selection_sort(tab);
    }

    tab = generate_random_vector(5000) ;
    {
        ScopedTimer timer("Tri fusion");
        merge_sort(tab);
    }

    tab = generate_random_vector(5000) ;
    {
        ScopedTimer timer("Tri std");
        std::sort(tab.begin(), tab.end());
    }


    std::vector<int> vec = {1, 2, 2, 3, 4, 8, 12};
    std::cout << "Indice de 8: " << search(vec, 8) << std::endl;

    vec = {1, 2, 3, 3, 6, 14, 12, 15};
    std::cout << "Indice de 15: " << search(vec, 15) << std::endl;

    vec = {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::cout << "Indice de 15: " << search(vec, 16) << std::endl;

    vec = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::cout << "Indice de 6: " << search(vec, 6) << std::endl;

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Indice de 10: " << search(vec, 10) << std::endl;

    return 0;
}