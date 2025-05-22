/**
 * LC: 103
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        if (root->left == nullptr && root->right == nullptr) {
            return vector<vector<int>>{{root->val}};
        }
        vector<vector<int>>ret;
        bool right2left = false;
        queue<TreeNode*> node_q;
        node_q.push(root);

        while (!node_q.empty()){
            vector<int>ret_lst;
            queue<TreeNode*> next_q;
            int curr_len = node_q.size();
            for (auto i = 0; i < curr_len; i++){
                auto next = node_q.front();
                node_q.pop();
                if (next->left != nullptr) {
                    next_q.push(next->left);
                } 
                if (next->right != nullptr) {
                    next_q.push(next->right);
                }
                
                ret_lst.push_back(next->val);
            }
            node_q = next_q;
            ret.push_back(vector<int>());
            int last_indx = ret.size() - 1;
            if (right2left){                
                ret[last_indx].assign(ret_lst.rbegin(), ret_lst.rend());
            } else {
                ret[last_indx] = ret_lst;
            }
            right2left = !right2left;
        }
        return ret;
    }
};

void test_empty_tree() {
    Solution sol;
    assert(sol.zigzagLevelOrder(nullptr).empty());
}

void test_single_node() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    assert(sol.zigzagLevelOrder(root) == std::vector<std::vector<int>>{{3}});
    delete root;
}

void test_typical_case() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::vector<std::vector<int>> expected = {{3}, {20, 9}, {15, 7}};
    assert(sol.zigzagLevelOrder(root) == expected);
    // Remember to deallocate memory (important in C++)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

}

void test_skewed_tree_left() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    std::vector<std::vector<int>> expected = {{1}, {2}, {3}};
    assert(sol.zigzagLevelOrder(root) == expected);
    delete root->left->left;
    delete root->left;
    delete root;
}

void test_skewed_tree_right() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    std::vector<std::vector<int>> expected = {{1}, {2}, {3}};
    assert(sol.zigzagLevelOrder(root) == expected);
    delete root->right->right;
    delete root->right;
    delete root;
}

void test_balanced_tree() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    std::vector<std::vector<int>> expected = {{1}, {3, 2}, {4, 5, 6, 7}};
    assert(sol.zigzagLevelOrder(root) == expected);
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;
}


int main() {
    test_empty_tree();
    test_single_node();
    test_typical_case();
    test_skewed_tree_left();
    test_skewed_tree_right();
    test_balanced_tree();

    std::cout << "All test cases passed!" << std::endl;
    return 0;
}

