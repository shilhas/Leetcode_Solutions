/**
 * See description LL 141
 */
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 

    bool hasCycle(ListNode *head) {
        ListNode *slow_p = head;
        ListNode *fast_p = head;
        if (head == nullptr) return false;
        while((fast_p != nullptr) && (fast_p->next != nullptr) && (slow_p != nullptr)) {
            slow_p = slow_p->next;
            if (fast_p->next != nullptr) {
                fast_p = fast_p->next->next;
            }
            if (fast_p == slow_p) break;
        }
        if ((fast_p != nullptr) && (fast_p->next != nullptr) && (slow_p != nullptr)) {
            return true;
        }
        else {
            return false;
        }
    }

typedef struct{
    vector<int> val;
    vector<int> indx;
    bool hascycle;
}TestVal_typ;

TestVal_typ tests[] = {
    {
        .val = vector<int>{3, 2, 0, -4},
        .indx = vector<int>{1, 2, 3, 1},
        .hascycle = true
    },
    {
        .val = vector<int>{1, 2},
        .indx = vector<int>{1, 0},
        .hascycle = true
    },
    {
        .val = vector<int>{1},
        .indx = vector<int>{INT_MAX},
        .hascycle = true
    }
};

ListNode * create_test_ll(TestVal_typ test) {
    unordered_map<int, ListNode*> ll_map;
    ListNode *ret = new ListNode(test.val[0]);
    ll_map[0] = ret;
    for (auto i = 0; i < test.indx.size(); i++) {

    }
}

int main (void) {
    for(auto test: tests) {
        ListNode *TestNode = create_test_ll(test);
        if(t.second == tmp) {
            cout << "Test Passed, input " << t.first << " Output " << t.second << endl;
        } else {
            cout << "Test Failed for input " << t.first << endl;
        }
    }
}