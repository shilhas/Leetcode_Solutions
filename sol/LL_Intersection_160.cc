/**
 * Find if 2 singly linked List intersect, if yes return the node where they intersect else return null
 */
#include <iostream>
#include <set>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode*> LL_vals;
    ListNode* LLA_head = headA;
    ListNode* LLB_head = headB;
    while(LLA_head != nullptr) {
        LL_vals.insert(LLA_head);
        LLA_head = LLA_head->next;
    }
    while(LLB_head != nullptr) {
        auto tmp = LL_vals.size();
        LL_vals.insert(LLB_head);
        if (LL_vals.size() == tmp){
            return LLB_head;
        } else {
            LLB_head = LLB_head->next;
        }
    }
    return nullptr;
}