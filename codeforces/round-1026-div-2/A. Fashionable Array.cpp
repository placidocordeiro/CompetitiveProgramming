#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

bool isFashionable(const std::vector<int>& array) {
    return (array.back() + array.front()) % 2 == 0;
}

void stepsToFashionable(const std::vector<int>& array, int steps, int& minSteps) {
    if (isFashionable(array)) {
        if (steps < minSteps) minSteps = steps;
        return;
    }
    if (array.size() <= 1 || steps >= minSteps) return;

    std::vector<int> popMax = array;
    popMax.pop_back();
    stepsToFashionable(popMax, steps + 1, minSteps);

    std::vector<int> popMin = array;
    popMin.erase(popMin.begin());
    stepsToFashionable(popMin, steps + 1, minSteps);
}

int main() {
    int t; // Number of test cases
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n; // Size of the array
        std::vector<int> array;
        
        for (int j = 0; j < n; ++j) {
            int x;
            std::cin >> x;
            array.push_back(x);
        }

        std::sort(array.begin(), array.end());
        
        int minSteps = std::numeric_limits<int>::max();

        stepsToFashionable(array, 0, minSteps);
        std::cout << minSteps << std::endl;
    }

    return 0;
}
