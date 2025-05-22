/**
 * See LC 105 for PS
 */
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

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
    unordered_map<int, int>val_map;
    deque<int> preorder_dq;
public:
    TreeNode* buildTree_helper(vector<int>& inorder, int offset=0){
        
        if (inorder.size() == 0) return nullptr;
        auto root_val = this->preorder_dq[0];
        this->preorder_dq.pop_front();
        TreeNode* root = new TreeNode(root_val);
        // find root in inorder version
        int i = this->val_map[root_val] - offset;
        vector<int> in_l = {inorder.begin(), inorder.begin()+i};
        vector<int> in_r = {inorder.begin()+i+1, inorder.end()};
        root->left = this->buildTree_helper(in_l, offset);
        root->right = this->buildTree_helper(in_r, offset+i+1);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0){
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); i++){
            this->val_map[inorder[i]] = i;
            this->preorder_dq.push_back(preorder[i]);
        }
        return this->buildTree_helper(inorder, 0);
    }
};

void dfs(TreeNode* root) {
    if (root == nullptr) return;
    dfs(root->left);
    cout << root->val<< " ";
    dfs(root->right);
}

int main() {
    pair<vector<int>, vector<int>> tests[]= {
        make_pair<vector<int>, vector<int>>({3,9,20,15,7}, {9,3,15,20,7}),
        make_pair<vector<int>, vector<int>>({4,2,1,3,6,5,7}, {1,2,3,4,5,6,7}),
    };
    Solution sol;
    for (auto test: tests) {
        auto ret = sol.buildTree(test.first, test.second);
        dfs(ret);
    }
}