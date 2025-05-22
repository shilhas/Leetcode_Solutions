
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char,int>char_map;
        for (auto ch: s) {
            char_map[ch]++;
        }
        for (char ch2: t) {
            if (char_map.find(ch2) == char_map.end()) return false;
            if (char_map[ch2] <= 0) return false;
            char_map[ch2]--;
        }
        return true;
    }
};

void runTests() {
    Solution solution;

    // Test cases
    assert(solution.isAnagram("anagram", "nagaram") == true);
    assert(solution.isAnagram("rat", "car") == false);
    assert(solution.isAnagram("aacc", "ccac") == false); // Different character counts
    assert(solution.isAnagram("", "") == true); // Empty strings
    assert(solution.isAnagram("ab", "a") == false); // Different lengths
    assert(solution.isAnagram("elephant", "phanteel") == true); // Different lengths

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}