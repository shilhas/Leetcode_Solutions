/**
 * See LC 11 for problem statement
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right) {
            int min_height;
            int width = right - left;
            if (height[left] > height[right]) {
                min_height = height[right];
                while (min_height >= height[right] && right > left) {
                    right--;
                }
            } else {
                min_height = height[left];
                while (min_height >= height[left] && right > left) {
                    left++;
                }
            }
            max_area = max(max_area, min_height*width);
        }

        return max_area;
    }
};