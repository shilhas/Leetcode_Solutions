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
        if ((fast_p != nullptr) && (fast_p->next != nullptr) && (slow_p != nullptr)) return true;
        else false;
    }

