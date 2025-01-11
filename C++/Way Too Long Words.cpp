#include <iostream>
#include <vector>

void printWord(const std::string& word) {
    if (word.length() > 10) {
        std::cout << word[0] << word.length() - 2 << word[word.length() - 1] << std::endl;
    } else {
        std::cout << word << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> strings(n);

    for(int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }

    for(const auto& word : strings) {
        printWord(word);
    }

    return 0;
}
