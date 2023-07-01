/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */



// @lc code=start
typedef struct Node {
    int val;
    int min;
    Node *next;

    Node(int v) {
        val = v;
        min = v;
        next = nullptr;
    }
};

class MinStack {

private:
    Node *head;

public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        Node *node = new Node(val);
        
        if (head == nullptr) {
            head = node;
            head->min = node->val;
            return;
        }

        if (head->min < node->min) {
            node->min = head->min;
        }
        node->next = head;
        head = node;
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

