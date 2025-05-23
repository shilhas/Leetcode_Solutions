/**
 * See leetcode problem statement 397
 */
#include <iostream>
#include <cassert>

using namespace std;

    int integerReplacement(long long n) {
        if (n == 1) return 0;
        if ((n % 2) == 0) {
            return 1 + integerReplacement(n/2);
        } else {
            if (n < 2147483647){
                return 1 + min(integerReplacement(n+1), integerReplacement(n-1));
            }
            return integerReplacement(n-1);
        }
    }

void testIntegerReplacement() {
  // Test Case 1: n = 8
  assert(integerReplacement(8) == 3);

  // Test Case 2: n = 7
  assert(integerReplacement(7) == 4);

  // Test Case 3: n = 1
  assert(integerReplacement(1) == 0);

  // Test Case 4: n = 3
  assert(integerReplacement(3) == 2);

  // Test Case 5: n = 65535
  assert(integerReplacement(65535) == 17);

  // Test Case 6: n = 100000000
  assert(integerReplacement(100000000) == 31);

  // Test Case 7: n = 2147483647 (INT_MAX)
  assert(integerReplacement(2147483647) == 32);

  std::cout << "All integerReplacement test cases passed!" << std::endl;
}

int main() {
  testIntegerReplacement();
  return 0;
}