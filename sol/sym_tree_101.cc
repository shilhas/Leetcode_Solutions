

/**
 Definition for a binary tree node.
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

    bool compare_nodes(TreeNode* node_left, TreeNode* node_right) {
      if ((node_left == nullptr) && (node_right == nullptr)) return true;
      else if ((node_left == nullptr) || (node_right == nullptr)) return false;
      else {
        if (node_left->val != node_right->val) return false;
        return compare_nodes(node_left->left, node_right->right) && 
               compare_nodes(node_left->right, node_right->left);
      }
    }
 

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare_nodes(root->left, root->right);
    }



void testIsSymmetric() {
  // Test Case 1: Empty tree
  TreeNode* root1 = nullptr;
  assert(isSymmetric(root1) == true);

  // Test Case 2: Single node tree
  TreeNode* root2 = new TreeNode(1);
  assert(isSymmetric(root2) == true);

  // Test Case 3: Symmetric tree
  TreeNode* root3 = new TreeNode(1, 
                                 new TreeNode(2, new TreeNode(3), new TreeNode(4)), 
                                 new TreeNode(2, new TreeNode(4), new TreeNode(3)));
  assert(isSymmetric(root3)  
 == true);

  // Test Case 4: Non-symmetric tree (different structure)
  TreeNode* root4 = new TreeNode(1, 
                                 new TreeNode(2, new TreeNode(3), nullptr), 
                                 new TreeNode(2, nullptr, new TreeNode(3)));
  assert(isSymmetric(root4) == true);

  // Test Case 5: Non-symmetric tree (different values)
  TreeNode* root5 = new TreeNode(1, 
                                 new TreeNode(2, new TreeNode(3), new TreeNode(4)), 
                                 new TreeNode(2, new TreeNode(3), new TreeNode(5)));
  assert(isSymmetric(root5) == false);

  // Test Case 6: Symmetric tree with one subtree null
  TreeNode* root6 = new TreeNode(1, new TreeNode(2), new TreeNode(2));
  assert(isSymmetric(root6) == true);

  // Test Case 7: Non-symmetric tree with one subtree null
  TreeNode* root7 = new TreeNode(1, new TreeNode(2), nullptr);
  assert(isSymmetric(root7) == false);

  // Test Case 8: More complex symmetric tree
  TreeNode* root8 = new TreeNode(1,
                                 new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), new TreeNode(5)),
                                 new TreeNode(2, new TreeNode(5), new TreeNode(3, nullptr, new TreeNode(4))));
  assert(isSymmetric(root8) == true);

  std::cout << "All isSymmetric test cases passed!" << std::endl;
}

int main() {
  testIsSymmetric();
  return 0;
}