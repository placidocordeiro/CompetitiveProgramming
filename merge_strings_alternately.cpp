// question 
// https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string finalWord = "";
        int i {0};

        while (i <= word1.size() || i <= word2.size())
        {
            if (i <= word1.size()) {
                finalWord += word1[i];
            }
            if (i <= word2.size()) {
                finalWord += word2[i];
            }
            i++;
        }
        return finalWord;
    }
};

int main() {
    std::string word1;
    std::string word2;
    Solution solution;

    std::cout << "insert the first word:" << std::endl;
    std::cin >> word1;
    std::cout << "insert the second word:" << std::endl;
    std::cin >> word2;

    std::cout << "the result is: " << solution.mergeAlternately(word1,word2) << endl;

    return 0;
}