
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <queue>

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
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

// Helper function to create a binary tree from a level order traversal vector
TreeNode* createTree(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to perform level order traversal of a binary tree
std::vector<int> levelOrder(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr) {
        return result;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        result.push_back(current->val);

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    return result;
}

void runTests() {
    Solution solution;

    // Test cases
    std::vector<int> tree1 = {4, 2, 7, 1, 3, 6, 9};
    std::vector<int> expected1 = {4, 7, 2, 9, 6, 3, 1};
    TreeNode* root1 = createTree(tree1);
    TreeNode* result1 = solution.invertTree(root1);
    assert(levelOrder(result1) == expected1);

    std::vector<int> tree2 = {2, 1, 3};
    std::vector<int> expected2 = {2, 3, 1};
    TreeNode* root2 = createTree(tree2);
    TreeNode* result2 = solution.invertTree(root2);
    assert(levelOrder(result2) == expected2);

    std::vector<int> tree3 = {};
    std::vector<int> expected3 = {};
    TreeNode* root3 = createTree(tree3);
    TreeNode* result3 = solution.invertTree(root3);
    assert(levelOrder(result3) == expected3);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}
