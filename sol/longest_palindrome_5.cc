/**
 * See LC 5 for problem statement
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        unordered_map<char, vector<int>> char_map;
        struct longest{
            int size;
            int start;
            int end;
        } max_palindrome = {.size = 0};
        
        for (int i = 0; i < s.length(); i++) {
            auto start = char_map.find(s[i]);
            if (start != char_map.end()) {
                for (auto start_indx : start->second){
                int end_indx = i;
                bool palindrome = true;
                while(start_indx <= end_indx){
                    if (s[start_indx] != s[end_indx]) {
                        palindrome = false;
                        break;
                    }
                    start_indx++;
                    end_indx--;
                }
                if (palindrome) {
                    int end = i + 1;
                    if (max_palindrome.size < (end - start->second)) {
                        max_palindrome.size = (end - start->second);
                        max_palindrome.start = start->second;
                        max_palindrome.end = end;
                    }
                }
            }
            } else {
                char_map[s[i]] = i;
            }
        }
        if (max_palindrome.size == 0) {
            return {s.begin(), s.begin() + 1};
        }
        return {s.begin()+ max_palindrome.start, s.begin()+max_palindrome.end};
    }
};

int main () {
    vector<string>tests = {
        "ccc",
        "malayalams",
        "taboo",
        "marathon",
        "abcd"
    };
    Solution sol;
    for (auto test: tests) {
        auto ret = sol.longestPalindrome(test);
        cout << "Biggest palindrome in "<< test << " is " << ret << endl; 
    }
}
