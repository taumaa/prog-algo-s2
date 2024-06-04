#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> reparations;

    for (auto const& robot : robots_fixes) {
        reparations[robot.first].push_back(robot.second);
    }

    return reparations;
}

float sum(std::vector<float> const& values) {
    float sum {0.0f};
    for (const float& value : values) {
        sum += value;
    }
    return sum;
}

void display_sum(std::unordered_map<std::string, std::vector<float>> const& reparations) {
    for (auto const& reparation : reparations) {
        std::cout << reparation.first << " : " << sum(reparation.second) << std::endl;
    }
}

int main() {



    return 0;
}