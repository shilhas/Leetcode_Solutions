/**
 * See LC 210 for PS
 */
#include <bits/stdc++.h>

using namespace std;

struct Node{
    vector<Node*> precedent_course;
    int course;
    bool course_complete;
    Node(int course):course(course), course_complete(false){}
};

class Solution {
    Node* get_courses(vector<int>& prerequisite, unordered_map<int, Node*>& course_map) {
        auto cm_dep = course_map.find(prerequisite[0]); 
        auto cm_pre = course_map.find(prerequisite[1]);
        Node* course_dep;
        Node* course_pre;
        if (cm_dep == course_map.end()) {
            course_dep = new Node(prerequisite[0]);
        } else {
            course_dep = course_map[prerequisite[0]];
        }
        if(cm_pre == course_map.end()) {
            course_pre = new Node(prerequisite[1]);
            course_map[prerequisite[1]] = course_pre;
        } else {
            course_pre = course_map[prerequisite[1]];
        }
        course_dep->precedent_course.push_back(course_pre);
        course_map[prerequisite[0]] = course_dep;
        return course_dep;
    }

    bool all_preceding_courses_completed(vector<Node*>& prerequisites) {
        for (auto prerequisite:prerequisites) {
            if (!prerequisite->course_complete) return false;
        }
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses < 2) return {0};
        vector<int>order;
        if (prerequisites.empty()) {
            vector<int>order(numCourses);
            std::iota(begin(order), end(order), 0);
            return order;
        }
        unordered_map<int, Node*>course_map;
        // build course map
        for(auto prerequisite:prerequisites) {
            course_map[prerequisite[0]] = get_courses(prerequisite, course_map);
        }
        queue<int>course_pending;
        // std::iota (std::begin(course_pending), std::end(v), 0);
        for (auto i = 0; i < numCourses; i++) {
            course_pending.push(i);
        }
        vector<bool>completed_course(numCourses, false);
        int num_course_completed = 0;
        while (num_course_completed < numCourses) {
            int q_count = course_pending.size();
            queue<int> nq;
            int cur_num_courses_comp = num_course_completed;
            // go through entire queue
            for (int i = 0; i < q_count; i++) {
                int course = course_pending.front();
                // check if the course can be completed
                Node* cp = course_map[course];
                if (cp == nullptr) {
                    order.push_back(course);
                    cur_num_courses_comp++;
                } else if (cp->precedent_course.empty() or all_preceding_courses_completed(cp->precedent_course)) {
                    // complete course
                    cp->course_complete = true;                    
                    order.push_back(course);
                    cur_num_courses_comp++;
                } else {
                    nq.push(course);
                }
                course_pending.pop();
            }
            if (cur_num_courses_comp == num_course_completed) { return {}; }
            num_course_completed = cur_num_courses_comp;
            course_pending = std::move(nq);
        }
        return order;
    }
};

int main() {
    vector<pair<int, vector<vector<int>>>> tests {
        make_pair(4, vector<vector<int>>{{1,0},{2,0},{3,1},{3,2}}),
        make_pair(6, vector<vector<int>>{{1,0},{2,0},{0,3},{3,4},{3,5}}),
        make_pair(3, vector<vector<int>>{{1,0}})
    };
    for(auto test: tests) {
        Solution sol;
        auto ret = sol.findOrder(test.first, test.second);
        if (ret.empty()) {
            cout << "Not possible to complete all the courses!\n";
        } else {
            cout << "All courses completed in order: ";
            for (auto val: ret) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
}