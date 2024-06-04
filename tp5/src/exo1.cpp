#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

size_t folding_string_hash(std::string const& s, size_t max) {
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        hash += s[i];
    }

    return hash % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        hash += s[i] * (i + 1);
    }

    return hash % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash = 0;
    size_t current_power = 1;

    for (char c : s) {
        size_t new_power = current_power * p;
        hash += (c * new_power) % m;
        current_power = new_power;
    }

    return hash;
}



int main() {

    return 0;
}