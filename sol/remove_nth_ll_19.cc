/**
 * See LC 19 for PS
 */
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode* br;
        ListNode* fr = head;
        ListNode* skipnode = head;
        while(fr != nullptr and n > 0) {
            fr = fr->next;
            n--;
        }
        
        // not enough node
        if (n) {
            return head;
        }

        while(fr != nullptr) {
            fr = fr->next;
            br = skipnode;
            skipnode = skipnode->next;
        }

        // node to remove is 1st node
        if (skipnode == head) {
            head = head->next;
        } else {
            br->next = skipnode->next;
        }
        skipnode->next = nullptr;

        return head;
    }
};

ListNode* vec_to_LL(vector<int>& vec) {
    if (vec.size() < 1) return nullptr;
    ListNode* ret = new ListNode(vec[0]);
    ListNode* next = ret;
    for (int i = 1; i < vec.size(); i++) {
        next->next = new ListNode(vec[i]);
        next = next->next;
    }
    return ret;
}

void LL_to_vec(ListNode* head, vector<int>& vec) {
    if (!head) return;
    while(head != nullptr) {
        vec.push_back(head->val);
        head = head->next;
    }
}

void print_vec(vector<int>& vec) {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}

int main() {
    vector<pair<vector<int>, int>>tests = {
        make_pair(vector{1,2,3,4,5}, 2),
        make_pair(vector{1,2,3,4,5}, 5),
        make_pair(vector{1,2,3,4,5}, 3),
    };
    Solution sol;
    for (auto test: tests) {
        auto in = vec_to_LL(test.first);
        auto ret = sol.removeNthFromEnd(in, test.second);
        vector<int> res;
        LL_to_vec(ret, res);
        cout << "Input list ";
        print_vec(test.first);
        cout << " after removing " << test.second << " node ";
        print_vec(res);
        cout << endl;
    }
}