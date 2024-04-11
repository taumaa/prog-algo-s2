#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Fonction pour trouver la longueur du premier mot
int first_word_length(std::string const& str) {
    auto const is_space = [](char letter){ return letter == ' '; };

    // Trouver le début du premier mot (non-espace)
    auto word_start = std::find_if_not(begin(str), end(str), is_space);
    // Trouver la fin du premier mot (espace après le mot)
    auto word_end = std::find_if(word_start, end(str), is_space);

    // Calculer la distance entre le début et la fin du premier mot
    return std::distance(word_start, word_end);
}

// Fonction pour découper une phrase en mots
std::vector<std::string> split_string(std::string const& str) {
    auto const is_space = [](char letter){ return letter == ' '; };
    std::vector<std::string> result;
    auto start = std::find_if_not(begin(str), end(str), is_space); // Début du premier mot
    auto end = start;

    while (start != str.end()) {
        // Trouver la fin du mot courant
        end = std::find_if(start, str.end(), is_space);
        // Ajouter le mot au vecteur
        result.emplace_back(start, end);
        // Trouver le début du mot suivant
        start = std::find_if_not(end, str.end(), is_space);
    }

    return result;
}

int main() {
    std::string phrase = "Voici un exemple de phrase avec des mots";
    std::cout << "Longueur du premier mot: " << first_word_length(phrase) << std::endl;

    auto mots = split_string(phrase);
    std::cout << "Mots de la phrase: ";
    for (const auto& mot : mots) {
        std::cout << "'" << mot << "' ";
    }
    std::cout << std::endl;

    return 0;
}