#include <iostream>

bool isBalanced(const std::string& s) {
    if (s.empty()) return true;
    int balance {0};
    for (char c : s) {
        if (c == '(') balance++;
        else if (c == ')') balance--;
        if (balance < 0) return false;
    }
    return (balance == 0) ? true : false;
}

void unbalancing(std::string& s) {
    if (!isBalanced(s)) {
        printf("YES\n");
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            std::string temp = s;
            temp.erase(i);
            for (int j = 0; j < temp.size(); j++) {
                if (temp[j] == ')') {
                    std::string temp1 = temp;
                    temp1.erase(j);
                    if (!isBalanced(temp1)) {
                        printf("YES\n");
                        return;
                    }
                }
            }
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;

        unbalancing(s);
    }

    return 0;
}