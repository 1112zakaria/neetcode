/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
struct Course {
    int id;
    int state;
    vector<Course*> postreqs;
};

enum Status {
    NOT_PROCESSED = 0,
    UNDER_PROCESSING,
    PROCESSED
};

class Solution {
public:
    /**
     * Approach (topological sort, O(?)):
     * - this question is asking you determine whether the course
     * schedule is a cyclic or acyclic. If acyclic, return true,
     * else return false
     * - note: use topological sort
     * - maintain a list of the states of each node
     *      - state 0: node has not been processed
     *      - state 1: node is under processing
     *      - state 2: node has been processed
     * - perform DFS on each of the nodes
     * - when a node's children are being processed, move the node to state 1
     * - when a node's children have been processed, move the node to state 2
     * - foreach node:
     *      - if it has already been processed, skip it
     *      - set its processing state to 1
     *      - DFS traverse all child nodes if their states == 0
     *      - if a child node has state == 1, return false
     *          - DFS traverse all the child nodes and mark as "under processing".
     * 
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // assumption: all courses are numbered from 0 to n, no skipping?
        vector<Course> nodes(numCourses);
        int a, b;
        // initialize all nodes
        for (int i=0; i<numCourses; i++) {
            nodes[i].id = i;
            nodes[i].state = 0;
        }
        // initialize postrequisites list
        for (vector<int> prereq : prerequisites) {
            a = prereq[0];
            b = prereq[1];
            nodes[b].postreqs.push_back(&nodes[a]);
        }
        // DFS traverse graph
        for (int i=0; i<numCourses; i++) {
            if (!helper(nodes[i])) {
                return false;
            }
        }
        return true;
    }

private:
    bool helper(Course &course) {
        if (course.state == UNDER_PROCESSING) {
            return false;
        }
        if (course.state == PROCESSED) {
            return true;
        }
        course.state = UNDER_PROCESSING;
        // process children
        for (Course *sequelCourse : course.postreqs) {
            if (!helper(*sequelCourse)) {
                return false;
            }
        }
        course.state = PROCESSED;
        return true;
    }
};
// @lc code=end

