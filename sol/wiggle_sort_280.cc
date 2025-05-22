/**
 * See problem statement for leetcode 280
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

    void wiggleSort(std::vector<int>& nums) {
        // check if num[i] relation to num[i+1] if relation is not correct swap
        if (nums.size() <= 1) return;
        for (auto i = 1; i < nums.size(); i++) {
            if (((i % 2 == 1) && (nums[i] < nums[i - 1])) || 
            ((i % 2 == 0) && (nums[i] > nums[i - 1]))) {
                std::swap(nums[i], nums[i-1]);
            }
        }
    }

// Helper function to check if an array is wiggle sorted
bool isWiggleSorted(const std::vector<int>& nums) {
  if (nums.size() <= 1) {
    return true;
  }
  for (int i = 1; i < nums.size(); ++i) {
    if ((i % 2 == 1 && nums[i] < nums[i - 1]) ||
        (i % 2 == 0 && nums[i] > nums[i - 1])) {
      return false;
    }
  }
  return true;
}

void testWiggleSort() {
  // Test Case 1: Empty array
  std::vector<int> nums1 = {};
  wiggleSort(nums1);
  assert(isWiggleSorted(nums1));

  // Test Case 2: Single element array
  std::vector<int> nums2 = {1};
  wiggleSort(nums2);
  assert(isWiggleSorted(nums2));

  // Test Case 3: Even length array
  std::vector<int> nums3 = {1, 5, 1, 1, 6, 4};
  wiggleSort(nums3);
  assert(isWiggleSorted(nums3));

  // Test Case 4: Odd length array
  std::vector<int> nums4 = {1, 3, 2, 2, 3, 1};
  wiggleSort(nums4);
  assert(isWiggleSorted(nums4));

  // Test Case 5: Array with duplicates
  std::vector<int> nums5 = {4, 5, 5, 6};
  wiggleSort(nums5);
  assert(isWiggleSorted(nums5));

  // Test Case 6: Sorted array
  std::vector<int> nums6 = {1, 2, 3, 4, 5};
  wiggleSort(nums6);
  assert(isWiggleSorted(nums6));

  std::cout << "All wiggleSort test cases passed!" << std::endl;
}

int main() {
  testWiggleSort();
  return 0;
}
