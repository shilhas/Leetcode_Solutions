/**
 * See LC 51 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n_val;
    vector<vector<string>>results;
public:
    void set_influence_d(int s_indx, int c_indx, vector<string>& influence, int indx_offset){
        if (s_indx >= this->n_val or c_indx >= this->n_val or s_indx < 0 or c_indx < 0) return;
        influence[s_indx][c_indx] = 'Q';
        set_influence_d(s_indx+indx_offset, c_indx+1, influence, indx_offset);
    }
    
    void set_influence_s(int s_indx, int c_indx, vector<string>& influence, int s_offset, int c_offset){
        if (s_indx >= this->n_val or c_indx >= this->n_val or s_indx < 0 or c_indx < 0) return;
        influence[s_indx][c_indx] = 'Q';
        set_influence_s(s_indx+s_offset, c_indx+c_offset, influence, s_offset, c_offset);
    }

    void set_influence(int s_indx, int c_indx, vector<string>& influence) {
        if (s_indx >= this->n_val or c_indx >= this->n_val) return;
    
        set_influence_s(s_indx, c_indx, influence, 1, 0);
        set_influence_s(s_indx-1, c_indx, influence, -1, 0);
        set_influence_s(s_indx, c_indx+1, influence, 0, 1);
        //set diagnal as well;
        set_influence_d(s_indx+1,c_indx+1,influence,1);
        set_influence_d(s_indx-1,c_indx+1,influence,-1);
    }

    void solve(int s_indx, int c_indx, vector<string>res, vector<string> influence) {
        // check each next column if there is a free slot to place the queen
        res[s_indx][c_indx] = 'Q';
        if (c_indx + 1 == this->n_val) {
            results.push_back(res);
            return;
        }
        set_influence(s_indx,c_indx,influence);
        for (int i = 0; i < this->n_val; i++) {
            if (influence[i][c_indx+1] == '.') {
                solve(i, c_indx+1, res, influence);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n < 2) return {{"Q"}};
        this->n_val = n;
        for (int i = 0; i < n; i++) {
            vector<string>res(n, string(n,'.'));
            vector<string>influence(n, string(n,'.'));
            solve(i, 0, res, influence);
        }
        return results;
    }
};

int main() {
    vector<int>tests {4, 5};
    for(auto test: tests) {
        Solution sol;
        auto res = sol.solveNQueens(test);
        cout << "For Input :" << test << " valid queen placements \n";
        int count = 1;
        for (auto vec: res) {
            cout <<"\n\nResult no " << count << "\n\n";
            for (auto val: vec) {
                cout << val << "\n";
            }
            count++;
        }
    }
}