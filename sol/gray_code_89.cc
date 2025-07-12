/**
 * See LC 89 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 1) {
            return {0};
        }
        vector<int>nn_firsthalf;
        vector<int>nn_sechalf;
        nn_firsthalf.push_back(0);
        nn_sechalf.push_back(1<<n-1);
        for (int i = 0; i < n-1; i++) {
            int or_val = 1<<i;
            auto rit = nn_firsthalf.rbegin();
            auto rit_sec = nn_sechalf.rbegin();
            {
                vector<int> v1, v2;
                while (rit != nn_firsthalf.rend()) {
                    v1.push_back(*rit++ | or_val);
                    v2.push_back(*rit_sec++ | or_val);
                }
                nn_firsthalf.insert(nn_firsthalf.end(), v1.begin(), v1.end());
                nn_sechalf.insert(nn_sechalf.end(), v2.begin(), v2.end());
            }
        }
        nn_firsthalf.insert(nn_firsthalf.end(), nn_sechalf.rbegin(),nn_sechalf.rend());
        return nn_firsthalf;
    }
};

template<typename T>
void print_vec(vector<T>vals) {
    for (T val: vals) {
        cout << val << "\t";
    }
    cout << "\n";
}

int main() {
    vector<int> tests = {
        1, 0, 2, 3, 4, 5
    };
    for (auto test: tests) {
        Solution sol;
        auto ret = sol.grayCode(test);
        cout << "---------- Generate code for ----------\nInput: " << test << endl;
        cout << "Output: ";
        print_vec(ret);
        cout << "\n-------------------------------------------\n";
    }
}