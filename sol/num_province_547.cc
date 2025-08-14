/**
 * See LC 547 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // void mark_province(vector<vector<int>>& isConnected, int row, int col, int count) {
    //     if (row < 0 or row >= isConnected.size() or col < 0 or col >= isConnected.size() or isConnected[row][col] == count) return;
    //     isConnected[row][col] = count;
    //     if ((row+1 < isConnected.size()) and isConnected[row+1][col] == 1) mark_province(isConnected, row+1, col, count);
    //     if ((col+1 < isConnected.size()) and isConnected[row][col+1] == 1) mark_province(isConnected, row, col+1, count);
    //     if ((row-1 >= 0) and isConnected[row-1][col] == 1) mark_province(isConnected, row-1, col, count);
    //     if ((col-1 >= 0) and isConnected[row][col-1] == 1) mark_province(isConnected, row, col-1, count);
    // }

    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 1) return 1;
        int count = 2;
        bool new_province = false;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[i][i] == 1) {
                queue<int>q;
                q.push(i);
                while(!q.empty()) {
                    // mark all connected nodes
                    int node = q.front();
                    q.pop();
                    isConnected[node][node] = count;
                    for (int j = 0; j < isConnected.size(); j++) {
                        if (isConnected[node][j] == 1) {
                            q.push(j);
                            isConnected[node][j] = count;
                        }
                    }
                }
                count++;
            }
        }
        return count - 2;
    }
};

template<typename T>
void print_vec(vector<T>vals) {
    for (T val: vals) {
        cout << val << "\t";
    }
    cout << "\n";
}

template<typename T>
void print_vecofvec(vector<vector<T>>& vecs) {
    for (auto vec: vecs) print_vec(vec);
} 

int main() {
    vector<vector<vector<int>>> tests = {
        {
            {1,0,0,1},
            {0,1,1,0},
            {0,1,1,1},
            {1,0,1,1}
        },
        {
            {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
            {0,1,0,1,0,0,0,0,0,0,0,0,0,1,0},
            {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,1,0,1,0,0,0,1,0,0,0,1,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
            {0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
            {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
            {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
        },
        {
            {1,1,0},
            {1,1,0},
            {0,0,1}
        },
        {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        },
        {
            {1,0,1,0,0,0},
            {0,1,1,1,1,0},
            {1,1,1,0,0,0},
            {0,1,0,1,0,0},
            {0,1,0,0,1,0},
            {0,0,0,0,0,1},
        }
    };

    for (auto test: tests) {
        Solution sol;
        auto ret = sol.findCircleNum(test);
        cout << "Input: \n";
        print_vecofvec(test);
        cout << "\nOutput: " << ret << "\n\n";
    }
}