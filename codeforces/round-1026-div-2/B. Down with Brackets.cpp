#include <iostream>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int balance = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance == 0) {
            if (i == n - 1) {
                std::cout << "NO" << std::endl;
            } 
            else {
                std::cout << "YES" << std::endl;
            }            
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (std::cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}