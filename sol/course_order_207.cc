/**
* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
* take course bi first if you want to take course ai.
*
* For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
* Return true if you can finish all courses. Otherwise, return false.
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
  unordered_map<int, vector<int>>map_prerequisite;
  vector<bool>course_completed;
  vector<bool>backlog;
public:
    bool dfs(int course) {
      // check if there any prerequisite
      if (map_prerequisite[course].empty()) {
        // complete course
        return course_completed[course] = true;
      }
      // there are prerequisites add current course to backlog      
      if (backlog[course]) return false;
      backlog[course] = true;

      // if prerequisites are fullfilled
      for (auto pre_course: map_prerequisite[course]) {
        if (course_completed[pre_course]) continue;
        if(!dfs(pre_course)) {
          return false;
        }
      }
      // now course can be complete, hence remove from backlog
      backlog[course] = false;
      return course_completed[course] = true;;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
      course_completed.resize(numCourses, false);
      backlog.resize(numCourses, false);
        
        for (auto p: prerequisites) {
          map_prerequisite[p[0]].push_back(p[1]);
          if (map_prerequisite.count(p[1]) == 0) {
            map_prerequisite[p[1]] = {};
          }
        }
        // dfs implementation with detection of cycle
        for (int i = 0; i < numCourses; i++) {
          if (course_completed[i]) continue;
          if (!dfs(i)) return false;
        }
        return true;
    }
};

int main() {
  vector<pair<int,vector<vector<int>>>> tests = {
    make_pair(5, vector<vector<int>>{{3,2}, {4,2}, {2,1}, {1,3}, {4,3}, {1,0}}), // not possible
    make_pair(5, vector<vector<int>>{{3,2}, {4,2}, {2,0}, {1,3}, {4,3}, {1,0}}), // possible
    make_pair(7, vector<vector<int>>{{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}})
  };
  for (auto test: tests) {
    Solution sol;
    if (sol.canFinish(test.first, test.second)){
      cout << "Course schedule is feasible\n";
    } else {
      cout << "Course schedule is not feasible\n";
    }
  }
}
