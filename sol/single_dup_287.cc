/**
 * See LC 287 for PS
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * Explaination: This problem is actually a linked list with cycle problem, to determine if a LL has cycle you use 2 pointers fast and slow
 * as with LL with cycle fast pointer and slow pointer will meet after sometime. Distance of point where they meet and the 
 * starting point to the duplicate number is always same hence the 2nd loop to traverse to the duplicate number
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow2 = 0;
        while(1) {
            slow2 = nums[slow2];
            slow = nums[slow];
            if (slow == slow2) break;
        }
        return slow2;
    }
};