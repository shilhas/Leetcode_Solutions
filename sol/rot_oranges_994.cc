/**
 * See LC 994 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool if_any_ripe(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 1 and grid[0].size() == 1) {
            return grid[0][0] == 1 ? -1:0;
        }

        int mins = -1;
        queue<pair<int,int>>q;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 2) {
                    q.push(make_pair(row, col));
                }
            }
        }
        if (q.empty()) return if_any_ripe(grid)? -1:0;
        while(!q.empty()) {
            queue<pair<int,int>> nq;
            auto push_2_q = [](int row, int col, queue<pair<int,int>>&q, vector<vector<int>>& grid) {
                if (grid[row][col] == 1) {
                    q.push(make_pair(row,col));
                    grid[row][col] = 2;
                }
            };
            int curr_size = q.size();
            for(int i = 0; i < curr_size; i++) {
                auto indx = q.front();
                // mark each valid adjacent indices rot
                if (indx.first - 1 > -1) {
                    push_2_q(indx.first - 1, indx.second, nq, grid);
                }
                if (indx.first + 1 < grid.size()) {
                    push_2_q(indx.first + 1, indx.second, nq, grid);
                }
                if (indx.second - 1 > -1) {
                    push_2_q(indx.first , indx.second - 1, nq, grid);
                }
                if (indx.second + 1 < grid[0].size()) {
                    push_2_q(indx.first, indx.second + 1, nq, grid);
                }
                q.pop();                
            }
            q = std::move(nq);
            mins++; 
        }
        
        
        return  if_any_ripe(grid)? -1:mins;
    }
};

int main() {
    vector<pair<vector<vector<int>>,int>>tests = {
        make_pair(vector<vector<int>>{{2,1,1},{1,1,0},{0,1,1}}, 4),
        make_pair(vector<vector<int>>{{1,1,1},{1,2,1},{1,1,1},{0,1,0}}, 2)
    };
    Solution sol;
    for (auto test: tests) {
        assert(sol.orangesRotting(test.first) == test.second);
    }
    cout << "All Tests passed!!\n";
}