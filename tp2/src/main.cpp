#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>


bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

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

int main() {

    std::vector<int> array {1, 10, 3, 4, 5, 6, 7, 8, 9};

    selection_sort(array);

    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    return 0;
}