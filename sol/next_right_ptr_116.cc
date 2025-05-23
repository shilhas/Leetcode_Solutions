/**
 * See problem statement for Leetcode 116
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}

    Node(int _val, Node* _left, Node* _right)
        : val(_val), left(_left), right(_right) {}
};

    void set_next_ptr(Node* curr, Node* adjacent) {
        if (curr != nullptr) {
            curr->next = adjacent;
            if (curr->left != nullptr) set_next_ptr(curr->left, curr->right);
            if (adjacent == nullptr){}
            if (curr->right != nullptr) {
                adjacent==nullptr? set_next_ptr(curr->right, nullptr):set_next_ptr(curr->right, adjacent->left);
            }
        }
    }

    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        set_next_ptr(root, nullptr);
        return root;
    }

void testConnect() {
  // Test Case 1: Empty tree
  Node* root1 = nullptr;
  assert(connect(root1) == nullptr);

  // Test Case 2: Single node tree
  Node* root2 = new Node(1);
  connect(root2);
  assert(root2->next == nullptr);

  // Test Case 3: Perfect binary tree
  Node* root3 = new Node(1, 
                          new Node(2), 
                          new Node(3));
//   root3->left = new Node(2);
//   root3->right = new Node(3);

  root3->left->left = new Node(4);
  root3->left->right = new Node(5);
  root3->right->left = new Node(6);
  root3->right->right = new Node(7);  

  connect(root3);
  assert(root3->left->next == root3->right);
  assert(root3->left->left->next == root3->left->right);
  assert(root3->left->right->next == root3->right->left);
  assert(root3->right->left->next == root3->right->right);
  assert(root3->right->right->next == nullptr);

  // Test Case 4: Incomplete binary tree
  Node* root4 = new Node(1, 
                          new Node(2, new Node(4), new Node(5)), 
                          new Node(3, nullptr, new Node(7)));
  connect(root4);
  assert(root4->left->next == root4->right);
  assert(root4->left->left->next == root4->left->right);
  assert(root4->left->right->next == root4->right->left); // This will be null
  assert(root4->right->left == nullptr);
  assert(root4->right->right->next == nullptr);

  std::cout << "All connect test cases passed!" << std::endl;
}

int main() {
  testConnect();
  return 0;
}