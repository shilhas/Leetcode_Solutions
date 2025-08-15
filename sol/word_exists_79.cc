/**
 * See LC 79 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exists_helper(vector<vector<char>>& board, string& word, int row, int col, vector<vector<bool>>& visited, int char_indx) {
        if (row < 0 or row >= board.size() or col < 0 or col >= board[0].size()) return false;
        if (visited[row][col]) return false;
        if (word[char_indx] != board[row][col]) {
            return false;
        }
        if (char_indx+1 == word.length()) return true;
        visited[row][col] = true;
        if (exists_helper(board, word, row, col+1, visited, char_indx+1)) {
            return true;
        }
        if (exists_helper(board, word, row, col-1, visited, char_indx+1)) {
            return true;
        }
        if (exists_helper(board, word, row+1, col, visited, char_indx+1)) {
            return true;
        }
        if (exists_helper(board, word, row-1, col, visited, char_indx+1)) {
            return true;
        }
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // find first character in the board
        char start = word[0];
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                // start from first char, search in all four direction for 2nd and mark each grid as visited when char found, to avoid multiple time inclusion
                if (board[row][col] == start) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    if (exists_helper(board, word, row, col, visited, 0)) {
                        return true;
                    }
                } 
            }
        }
        return false;        
    }
};

#include "print_helper.h"

typedef struct {
    vector<vector<char>>board;
    string word;
} TestInputType;

int main() {
    vector<string> rows = {"ABCE", "SFCS", "ADEE"};
    vector<vector<char>> test_board(rows.size());
    for (int i = 0; i < rows.size(); i++) {
        for(int j = 0; j < rows[i].length(); j++) {
            test_board[i].push_back(rows[i][j]);
        }
    }


    vector<TestInputType>tests = {
        {
            .board = test_board, .word = "ABCCED"
        }
        ,
        {
            .board = test_board,
            .word = "SEE"
        },
        {
            .board = test_board,
            .word = "ABCB"
        }
    };

    for (auto test: tests) {
        Solution sol;
        auto ret = sol.exist(test.board, test.word);
        cout << "In board: \n";
        print_vecofvec(test.board);
        cout << "Word " << test.word;
        if (ret == true) {
            cout << " exists\n\n";
        } else {
            cout << " doesn't exists\n\n";
        }
    }
}