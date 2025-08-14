/**
 * See LC 77 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> get_combi(int& n, int k, int start) {
        if (start+k > n+1 or k == 0) return {{}};
        
        vector<vector<int>>ret;
        if (k == 1) {
            ret.resize(n+1-start, vector<int>(1));
            int indx = 0;
            for (int i = start; i <= n; i++) {
                ret[indx][0] = i;
                indx++;
            }
            return ret;
        }
        for (int i = start; i < n; i++) {
            // get k-1 combination from start + 1
            auto tmp2 = get_combi(n, k-1, i+1);
            for (int j = 0; j < tmp2.size(); j++) {
                if (tmp2[j].size() != k-1) {
                    tmp2.clear();
                    break;
                }
                tmp2[j].push_back(i);
            }
            if (tmp2.size() > 0)
            ret.insert(ret.end(), tmp2.begin(), tmp2.end());
        }
        return ret;
    } 

    vector<vector<int>> combine(int n, int k) {
        return get_combi(n, k, 1);
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