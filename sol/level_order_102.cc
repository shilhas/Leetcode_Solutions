/**
 * See LC 102 for PS
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {{}};
        vector<vector<int>> ret;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> rq;
            vector<int> level;
            while(!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if (curr->left != nullptr) rq.push(curr->left);
                if (curr->right != nullptr) rq.push(curr->right);
            }
            ret.push_back(level);
            q = std::move(rq);
        }
        return ret;
    }
};