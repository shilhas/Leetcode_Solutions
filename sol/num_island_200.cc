/**
 * See LC 200 for PS
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void mark_visited(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 or row >= grid.size()) return;
        if (col < 0 or col >= grid[0].size()) return;
        if (grid[row][col] == '1' and visited[row][col] == false) {
            visited[row][col] = true;
            mark_visited(grid, visited, row+1, col);
            mark_visited(grid, visited, row, col+1);
            mark_visited(grid, visited, row-1, col);
            mark_visited(grid, visited, row, col-1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        if ( grid.size() < 2 and grid[1].size() < 2 ) {
            return grid[0][0] == '1' ?  1:0;
        }
        const int row_count = grid.size();
        const int col_count = grid[0].size();
        vector<vector<bool>>visited(row_count,vector<bool>(grid[0].size(), false));

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (visited[row][col] == false and grid[row][col] == '1') {
                    mark_visited(grid, visited, row, col);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> test = {
        {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}
    };
    Solution sol;
    auto ret = sol.numIslands(test);
    cout << ret << endl;
}