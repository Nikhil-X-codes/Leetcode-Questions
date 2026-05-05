class MinStack {
public:

   stack<int>st,mini;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if(mini.empty() || val <= mini.top()){
            mini.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        
        if(st.empty()) return;

        if(st.top() == mini.top()){
mini.pop();
        }

        st.pop();
    }
    
    int top() {
        
        if(st.empty()) return -1;

        return st.top();
    }
    
    int getMin() {
        
        return mini.top();
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
