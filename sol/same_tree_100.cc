

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
 

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == nullptr) && (q == nullptr)) return true;
        else if ((p == nullptr) || (q == nullptr)) return false;
        else {
            if (p->val != q->val) return false;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }



void testIsSameTree() {
  // Test Case 1: Both trees are null
  TreeNode* p1 = nullptr;
  TreeNode* q1 = nullptr;
  assert(isSameTree(p1, q1) == true);

  // Test Case 2: One tree is null, the other is not
  TreeNode* p2 = new TreeNode(1);
  TreeNode* q2 = nullptr;
  assert(isSameTree(p2, q2) == false);

  // Test Case 3: Both trees have a single node with the same value
  TreeNode* p3 = new TreeNode(1);
  TreeNode* q3 = new TreeNode(1);
  assert(isSameTree(p3, q3) == true);

  // Test Case 4: Both trees have a single node with different values
  TreeNode* p4 = new TreeNode(1);
  TreeNode* q4 = new TreeNode(2);
  assert(isSameTree(p4, q4) == false);

  // Test Case 5: Simple identical trees
  TreeNode* p5 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode* q5 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  assert(isSameTree(p5, q5) == true);

  // Test Case 6: Trees with different structures
  TreeNode* p6 = new TreeNode(1, new TreeNode(2), nullptr);
  TreeNode* q6 = new TreeNode(1, nullptr, new TreeNode(2));
  assert(isSameTree(p6, q6) == false);

  // Test Case 7: Trees with different values
  TreeNode* p7 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode* q7 = new TreeNode(1, new TreeNode(2), new TreeNode(4));
  assert(isSameTree(p7, q7) == false);

  // Test Case 8: More complex identical trees
  TreeNode* p8 = new TreeNode(1, 
                              new TreeNode(2, new TreeNode(4), nullptr), 
                              new TreeNode(3));
  TreeNode* q8 = new TreeNode(1, 
                              new TreeNode(2, new TreeNode(4), nullptr), 
                              new TreeNode(3));
  assert(isSameTree(p8, q8) == true);

  // Test Case 9: More complex different trees (different structure)
  TreeNode* p9 = new TreeNode(1, 
                              new TreeNode(2, new TreeNode(4), nullptr), 
                              new TreeNode(3));
  TreeNode* q9 = new TreeNode(1, 
                              new TreeNode(2, nullptr, new TreeNode(4)), 
                              new TreeNode(3));
  assert(isSameTree(p9, q9) == false);

  // Test Case 10: More complex different trees (different values)
  TreeNode* p10 = new TreeNode(1, 
                              new TreeNode(2, new TreeNode(4), nullptr), 
                              new TreeNode(3));
  TreeNode* q10 = new TreeNode(1, 
                               new TreeNode(2, new TreeNode(5), nullptr), 
                               new TreeNode(3));
  assert(isSameTree(p10, q10) == false);

  std::cout << "All isSameTree test cases passed!" << std::endl;
}

int main() {
  testIsSameTree();
  return 0;
}