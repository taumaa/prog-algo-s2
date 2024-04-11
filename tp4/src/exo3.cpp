#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(std::string const& str) {
    // Comparaison de la chaîne avec sa version inversée
    return std::equal(std::begin(str), std::end(str), std::rbegin(str), std::rend(str));
}

int main() {
    std::string test1 = "radar";
    std::string test2 = "hello";

    std::cout << "Le mot '" << test1 << "' est un palindrome? " << (is_palindrome(test1) ? "Oui" : "Non") << std::endl;
    std::cout << "Le mot '" << test2 << "' est un palindrome? " << (is_palindrome(test2) ? "Oui" : "Non") << std::endl;

    return 0;
}