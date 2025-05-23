/**
 * Of all the given gas station determine the station where you can start the journey and 
 * complete the circular trip back. Only one station is the right station to start others will 
 * not 
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_tank_lvl = 0;
        int total_tank_lvl = 0;
        int station_indx = 0;
        const int station_count = cost.size();

        for (int i = 0; i < station_count; i++) {
            total_tank_lvl += (gas[i] - cost[i]);
            curr_tank_lvl +=  (gas[i] - cost[i]);
            if (curr_tank_lvl < 0) {
                station_indx = i + 1;
                curr_tank_lvl = 0;
            }
        }
        return (total_tank_lvl >= 0) ? station_indx:-1;
    }

void testCanCompleteCircuit() {
  // Test Case 1: Basic case
  std::vector<int> gas1 = {1, 2, 3, 4, 5};
  std::vector<int> cost1 = {3, 4, 5, 1, 2};
  assert(canCompleteCircuit(gas1, cost1) == 3);

  // Test Case 2:  Cannot complete circuit
  std::vector<int> gas2 = {2, 3, 4};
  std::vector<int> cost2 = {3, 4, 3};
  assert(canCompleteCircuit(gas2, cost2) == -1);

  // Test Case 3: Starting at the last station
  std::vector<int> gas3 = {5, 1, 2, 3, 4};
  std::vector<int> cost3 = {4, 4, 1, 5, 1};
  assert(canCompleteCircuit(gas3, cost3) == 4);

  // Test Case 4:  All gas stations have same gas and cost
  std::vector<int> gas4 = {2, 2, 2};
  std::vector<int> cost4 = {2, 2, 2};
  assert(canCompleteCircuit(gas4, cost4) == 0); // Any station can be the starting point

  // Test Case 5: More complex case
  std::vector<int> gas5 = {3, 1, 1};
  std::vector<int> cost5 = {1, 2, 2};
  assert(canCompleteCircuit(gas5, cost5) == 0);

  std::cout << "All canCompleteCircuit test cases passed!" << std::endl;
}

int main() {
  testCanCompleteCircuit();
  return 0;
}