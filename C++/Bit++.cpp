#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int x {0};

    for(int i {0}; i<n; i++) {
        std::string operation;
        std::cin >> operation;
        operation.find("++") != std::string::npos ? x++ : x--;
    }

    std::cout << x;

    return 0;
}
