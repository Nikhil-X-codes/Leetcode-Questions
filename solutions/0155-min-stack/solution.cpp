class MinStack {
    stack<int> s1, minst;

public:
    MinStack() {}

    void push(int val) {

        s1.push(val);

        if (minst.empty() || val <= minst.top()) {
            minst.push(val);
        }
    }

    void pop() {

        if (s1.top() == minst.top()) {
            minst.pop();
        }
        s1.pop();
    }

    int top() { return s1.top(); }

    int getMin() { return minst.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
