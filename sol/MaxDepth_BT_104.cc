/**
* See LC 104 for problem statement
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:

    int maxDepth(TreeNode* root) {
        // Can root be null? Yes
        if (root == nullptr) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


// Helper function to create a simple tree for testing.
TreeNode* createTree(std::initializer_list<int> values) {
    if (values.size() == 0) {
        return nullptr;
    }
    auto it = values.begin();
    TreeNode* root = new TreeNode(*it++);
    std::vector<TreeNode*> nodes = {root};

    for (size_t i = 0; i < nodes.size() && it != values.end(); ++i) {
        if (*it != -1) { // -1 represents null
            nodes[i]->left = new TreeNode(*it);
            nodes.push_back(nodes[i]->left);
        }
        ++it;
        if (it != values.end() && *it != -1) {
            nodes[i]->right = new TreeNode(*it);
            nodes.push_back(nodes[i]->right);
        }
        ++it;
    }
    return root;
}

//Helper function to free the allocated memory of a tree
void deleteTree(TreeNode* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void testMaxDepth() {
    Solution sol;
    // Test case 1: Empty tree
    assert(sol.maxDepth(nullptr) == 0);

    // Test case 2: Single node tree
    TreeNode* root2 = new TreeNode(1);
    assert(sol.maxDepth(root2) == 1);
    delete root2;

    // Test case 3: Simple tree
    TreeNode* root3 = createTree({3, 9, 20, -1, -1, 15, 7});
    assert(sol.maxDepth(root3) == 3);
    deleteTree(root3);

    // Test case 4: Skewed left tree
    TreeNode* root4 = createTree({1, 2, -1, 3, -1, -1, -1, 4});
    assert(sol.maxDepth(root4) == 3);
    deleteTree(root4);

    // Test case 5: Skewed right tree
    TreeNode* root5 = createTree({1, -1, 2, -1, -1, -1, 3, -1, -1, -1, 4});
    assert(sol.maxDepth(root5) == 2);
    deleteTree(root5);

    //Test case 6: More complex tree.
    TreeNode* root6 = createTree({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    assert(sol.maxDepth(root6) == 4);
    deleteTree(root6);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    testMaxDepth();
    return 0;
}