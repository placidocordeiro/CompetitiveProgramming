#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> scores(n);

    int count {0};
    for(int i = 0; i < n; i++) {
        std::cin >> scores[i];
    }

    for(int score : scores) {
        if(score >= scores[k-1]) count++;
    }

    std::cout << count;

    return 0;
}
