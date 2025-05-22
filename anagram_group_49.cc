/**
 * See LC 49 for problem statement
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// string merge_string(string s1, string s2){
//     int ri = 0;
//     int i = 0;
//     string res = "";
//     for (auto c: s2) {
//         while(s1[i] < c) {
//             res += s1[i];
//             i++;
//         }
//         res += c;
//     }
//     return res;
// }

// void sort_string(string& str) {
//     int sz = 1;
//     const int len = str.length();
//     if (len < 2) {
//         return;
//     }
//     do {
//         for (auto i = 0; i < len; i += sz*2) {
//             str.replace(i, 2*sz, merge_string(str.substr(i, sz), str.substr(i + sz, sz)));
//         }
//     } while (sz < len);    
// }



using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        cout << "Input strings:\n";
        unordered_map<string, vector<string>> anagram_map;
        for (auto s: strs) {
            string s_cp = s;
            sort(s.begin(), s.end());
            anagram_map[s].push_back(s_cp);
        }
        vector<vector<string>> res;
        for (auto it = anagram_map.begin(); it != anagram_map.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};

int main() {
    vector<string> test = {"eat","tea","tan","ate","nat","bat"};
    Solution sol;
    int i = 1;
    auto ret = sol.groupAnagrams(test);
    for (auto vec: ret){
        cout << "Anagram no. " << i << ": \n";
        for (auto s: vec) {
            cout << s << "\t";
        }
        cout << "\n";
        i++;
    }
}