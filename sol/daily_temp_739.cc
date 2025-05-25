/**
 * See LC 739 for PS
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.size() < 2) return {0};
        stack<int> pending;
        vector<int>ret(temperatures.size(), 0);
        pending.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            while (!pending.empty() and temperatures[i] > temperatures[pending.top()]) {
                int day = pending.top();
                pending.pop();
                ret[day] = i - day;
            }
            pending.push(i);
        }
        return ret;
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
    vector<vector<int>> tests = {
        {17, 18, 14, 13, 12, 11},
        {17, 18, 14, 13, 12, 19},
        {17}
    };
    Solution sol;
    for (auto test:tests) {
        auto ret = sol.dailyTemperatures(test);
        cout << "for input :";
        print_vec(test);
        cout << "Result: ";
        print_vec(ret);
    }
}