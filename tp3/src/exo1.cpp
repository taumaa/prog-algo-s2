#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <stack>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(const std::string& s) {
    bool has_point = false; // pour suivre si on a déjà rencontré un point

    for (char c : s) {
        if (std::isdigit(c)) {
            continue; // c'est un chiffre, on continue
        } else if (c == '.' && !has_point) {
            has_point = true; // c'est le premier point qu'on rencontre
        } else {
            return false; // si c n'est ni un chiffre ni un point, ou si on a déjà un point, la chaîne n'est pas un nombre flottant
        }
    }

    // On retourne vrai seulement si la chaîne n'est pas vide et, si elle contient un point, il doit y avoir des chiffres avant et après
    return !s.empty() && (has_point ? s.find('.') != 0 && s.find('.') != s.length() - 1 : true);
}

float npi_evaluate(std::vector<std::string> const& tokens) {
    // Declarer une pile
    std::stack<float> stack;

    // Pour chaque token
    for (std::string const& token : tokens) {
        // Si le token est un nombre on l'ajoute dans la pile
        if (is_floating(token)) {
            stack.push(std::stof(token));
        } else {
            // Sinon si le token est un opérateur on dépile les deux derniers éléments de la pile, on les opère et on empile le résultat
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();

            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Invalid operator");
            }
        }

    }

    // On retourne le dernier élément de la pile
    return stack.top();
}

int main() {

    std::string npi;
    // L'user saisit une chaîne
    std::cout << "Saisir une chaîne : ";
    std::getline(std::cin, npi);

    std::vector<std::string> tokens = split_string(npi);

    std::cout << "Res: " << npi_evaluate(tokens) << std::endl;

    return 0;
}