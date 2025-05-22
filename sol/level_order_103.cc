#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ret;
        
        queue<TreeNode*> node_q;
        node_q.push(root);
        bool lefttoRight = true;
        while(!node_q.empty()) {
            int entries_curr_level = node_q.size();
            vector<int> node_val(entries_curr_level);
            for (auto i = 0; i < entries_curr_level; i++){
                TreeNode* nxt_node = node_q.front();
                int curr_indx = lefttoRight? i: (entries_curr_level - 1 -i);
                node_q.pop();
                node_val[curr_indx] = (nxt_node->val);
                if (nxt_node->left)
                    node_q.push(nxt_node->left);
                if (nxt_node->right)
                    node_q.push(nxt_node->right);
            }
            lefttoRight = !lefttoRight;
            ret.push_back(node_val);
        }

        return ret;
    }


void testZigzagLevelOrder() {
  // Test Case 1: Empty tree
  TreeNode* root1 = nullptr;
  std::vector<std::vector<int>> expected1 = {};
  assert(zigzagLevelOrder(root1) == expected1);

  // Test Case 2: Single node tree
  TreeNode* root2 = new TreeNode(1);
  std::vector<std::vector<int>> expected2 = {{1}};
  assert(zigzagLevelOrder(root2) == expected2);

  // Test Case 3: Simple tree
  TreeNode* root3 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  std::vector<std::vector<int>> expected3 = {{3}, {20, 9}, {15, 7}};
  assert(zigzagLevelOrder(root3) == expected3);

  // Test Case 4: Another tree
  TreeNode* root4 = new TreeNode(1, 
                                 new TreeNode(2, new TreeNode(4), nullptr), 
                                 new TreeNode(3, nullptr, new TreeNode(5)));
  std::vector<std::vector<int>> expected4 = {{1}, {3, 2}, {4, 5}};
  assert(zigzagLevelOrder(root4) == expected4);

  // Test Case 5: More complex tree
  TreeNode* root5 = new TreeNode(1,
                                 new TreeNode(2, new TreeNode(4, new TreeNode(7), nullptr), new TreeNode(5)),
                                 new TreeNode(3, new TreeNode(6), new TreeNode(8, nullptr, new TreeNode(9))));
  std::vector<std::vector<int>> expected5 = {{1}, {3, 2}, {4, 5, 6, 8}, {9, 7}};
  assert(zigzagLevelOrder(root5) == expected5);

  std::cout << "All zigzagLevelOrder test cases passed!" << std::endl;
}

int main() {
  testZigzagLevelOrder();
  return 0;
}