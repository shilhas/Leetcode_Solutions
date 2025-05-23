/**
 * See LC 114 for PS
 */

#include <iostream>
#include <vector>

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
    void get_nodes(vector<TreeNode*>& nodes, TreeNode* root) {
        if (root == nullptr) return;
        nodes.push_back(root);
        this->get_nodes(nodes, root->left);
        this->get_nodes(nodes, root->right);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        this->get_nodes(nodes, root);
        root->left = nullptr;
        TreeNode** next = &root->right;
        for (auto i = 1; i < nodes.size(); i++) {
            *next = nodes[i];
            (*next)->left = nullptr;
            next = &(*next)->right;
        }
    }
};

int main() {
    TreeNode* test_root = new TreeNode(1, new TreeNode(2, new TreeNode(5, nullptr, nullptr), new TreeNode(4, nullptr, nullptr)), new TreeNode(3, nullptr, nullptr));
    Solution sol;
    sol.flatten(test_root);
}