/**
 * See LC 77 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void get_combi(int& n, int k, int start, vector<int>&curr, vector<vector<int>>&res) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        if (start > n) return;

        for(int i = start; i <= n; i++) {
            curr.push_back(i);
            get_combi(n, k, i+1,curr, res);
            curr.pop_back();
        }
    } 

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>curr;
        get_combi(n, k, 1, curr, res);
        return res;
    }
};

#include "print_helper.h"

int main() {
    vector<vector<int>>tests = {
        {4, 2},
        {4, 3},
        {5, 3}
    };
    for (auto test: tests) {
        Solution sol;

        auto res = sol.combine(test[0], test[1]);
        cout << "Input: ";
        print_vec(test);
        cout << "\nResult: ";
        print_vecofvec(res);
        cout << "\n\n";
    }
}