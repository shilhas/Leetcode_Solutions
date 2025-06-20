/**
 * See LC 199 for PS
 */
#include <bits/stdc++.h>

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ret;
        deque<TreeNode*> curr_level;
        curr_level.push_back(root);
        while(!curr_level.empty()) {
            int curr_size = curr_level.size();
            ret.push_back(curr_level.back()->val);
            while (curr_size--) {
                auto tmp = curr_level.front();
                if (tmp->left) curr_level.push_back(tmp->left);
                if (tmp->right) curr_level.push_back(tmp->right);
                curr_level.pop_front();
            }         
        }
        return ret;
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(5,nullptr, nullptr),nullptr),nullptr), new TreeNode(3, nullptr, nullptr));
    Solution sol;
    auto ret = sol.rightSideView(root);
    cout << "Result: ";
    for (auto v: ret) {
        cout << v << "\t";
    }
    cout << "\n\n";
}