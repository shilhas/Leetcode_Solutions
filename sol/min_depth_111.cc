/**
 * see description leetcode 111
 */

#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left != nullptr && root->right != nullptr) {
            return 1 + std::min(minDepth(root->left), minDepth(root->right));
        } else if (root->left != nullptr) {
            return 1 + minDepth(root->left);
        } else if (root->right != nullptr) {
            return 1 + minDepth(root->right);
        } else return 1;
    }


void testMinDepth() {
  // Test Case 1: Empty tree
  TreeNode* root1 = nullptr;
  assert(minDepth(root1) == 0);

  // Test Case 2: Single node tree
  TreeNode* root2 = new TreeNode(1);
  assert(minDepth(root2) == 1);

  // Test Case 3: Left-skewed tree
  TreeNode* root3 = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
  assert(minDepth(root3) == 3);

  // Test Case 4: Right-skewed tree
  TreeNode* root4 = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
  assert(minDepth(root4) == 3);

  // Test Case 5: Complete binary tree
  TreeNode* root5 = new TreeNode(3, 
                                 new TreeNode(9), 
                                 new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  assert(minDepth(root5) == 2);

  // Test Case 6: Incomplete binary tree
  TreeNode* root6 = new TreeNode(1, 
                                 new TreeNode(2, new TreeNode(3), nullptr), 
                                 new TreeNode(4));
  assert(minDepth(root6) == 2);

  // Test Case 7: Tree with one child at each level
  TreeNode* root7 = new TreeNode(1, 
                                 new TreeNode(2, nullptr, new TreeNode(3, new TreeNode(4), nullptr)), 
                                 nullptr);
  assert(minDepth(root7) == 4);

  std::cout << "All minDepth test cases passed!" << std::endl;
}

int main() {
  testMinDepth();
  return 0;
}