/**
 * Given list of childrens with rank distribute chocolate taking into consideration their rank. 
 * Each neighbor with hire rank get's at least one chocolate more than the lower ranked kid. 
 * Each kid get's at least one chocolate
 * Return minimum number of chocolate need for the this distribution for given set of childrens
 */
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

    void decreasing_ranking(int dec_count, int last_indx, vector<int> &choco_dist) {
        for (auto j = last_indx; j > (last_indx - dec_count); j--) {
            choco_dist[j-1] = std::max(choco_dist[j] + 1, choco_dist[j-1]);
        }
    }

    int candy(vector<int>& ratings) {
        int r_len = ratings.size();
        vector<int> chocolate(r_len, 1);
        int dec_len = 0;

        for (auto i = 0; i < r_len - 1; i++) {
            if (ratings[i] > ratings[i + 1]) {
                dec_len ++;
            } else {
                if (dec_len > 0) {
                    decreasing_ranking(dec_len, i, chocolate);
                    dec_len = 0;
                }  
                if (ratings[i] < ratings[i + 1]) {
                    chocolate[i + 1] = chocolate[i] + 1;
                }
            }
        }
        if (dec_len) {
            decreasing_ranking(dec_len, r_len-1, chocolate);
            dec_len = 0;
        }

        int sum = 0;
        for (auto val: chocolate) {
            sum += val;
        }
        return sum;
    }

void testCandy() {
  // Test Case 1: Empty ratings
  std::vector<int> ratings1 = {};
  assert(candy(ratings1) == 0);

  // Test Case 2: Single child
  std::vector<int> ratings2 = {1};
  assert(candy(ratings2) == 1);

  // Test Case 3: Increasing ratings
  std::vector<int> ratings3 = {1, 3, 4, 5, 2};
  assert(candy(ratings3) == 11);

  // Test Case 4: Decreasing ratings
  std::vector<int> ratings4 = {5, 4, 3, 2, 1};
  assert(candy(ratings4) == 15);

  // Test Case 5: Mixed ratings
  std::vector<int> ratings5 = {1, 3, 2, 2, 1};
  assert(candy(ratings5) == 7);

  // Test Case 6: Another mixed ratings
  std::vector<int> ratings6 = {1, 2, 87, 87, 87, 2, 1};
  assert(candy(ratings6) == 13);

  // Test Case 7: More complex case
  std::vector<int> ratings7 = {1, 0, 2};
  assert(candy(ratings7) == 5);

  // Test Case 8: Increasing ratings
  std::vector<int> ratings8 = {0, 1, 2, 3, 2, 1};
  assert(candy(ratings8) == 13);

  std::cout << "All candy test cases passed!" << std::endl;
}

int main() {
  testCandy();
  return 0;
}