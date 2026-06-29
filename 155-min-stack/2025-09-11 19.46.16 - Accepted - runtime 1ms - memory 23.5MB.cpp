class MinStack {
    stack<int> MainStack;
    stack<int> MinnStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        MainStack.push(val);
        if(MinnStack.empty() || val<=MinnStack.top()) MinnStack.push(val);
    }
    
    void pop() {
        if(MainStack.top()==MinnStack.top()){
            MainStack.pop();
            MinnStack.pop();
        }
        else MainStack.pop();
    }

    
    int top() {
        return MainStack.top();
    }
    
    int getMin() {
        return MinnStack.top();
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