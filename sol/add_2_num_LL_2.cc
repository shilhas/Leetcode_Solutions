/**
 * See LC 2 for PS
 */
#include <bits/stdc++.h>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        int carry = 0;
        ListNode* res = nullptr;
        ListNode** next = &res;
        auto get_val = [](ListNode* &ll) ->int{
            if (ll != nullptr) {
                int ret = ll->val;
                ll = ll->next;
                return ret;
            }
            return 0;
        };
        while(l1 != nullptr or l2 != nullptr or carry != 0) {
            int sum = carry;
            sum += get_val(l1);
            sum += get_val(l2);

            *next = new ListNode(sum%10);
            carry = sum / 10;
            next =  &((*next)->next);
        }

        return res;
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

typedef struct{
    vector<int> l1;
    vector<int> l2;
    vector<int> res;
}Input_t;

int main() {
    vector<Input_t>tests = {
        {
            .l1 = vector<int>{2,4,3},
            .l2 = vector<int>{5,6,4},
            .res = vector<int>{7, 0, 8}
        },
        {
            .l1 = vector<int>{9,9,9,9,9,9,9},
            .l2 = vector<int>{9,9,9,9},
            .res = vector<int>{8,9,9,9,0,0,0,1}
        }
        // make_pair(vector<int>{2,4,3},vector<int>{2,4,3}),
    };

    Solution sol;
    for (auto test: tests) {
        auto l1 = vec_to_LL(test.l1);
        auto l2 = vec_to_LL(test.l2);
        auto ret = sol.addTwoNumbers(l1, l2);
        for (auto val: test.res) {
            if (ret == nullptr or ret->val != val) {
                cout << "Test failed!\n";
            }
            ret = ret->next;
        }
        cout << "Test passed: result == expected!\n";
    }
}