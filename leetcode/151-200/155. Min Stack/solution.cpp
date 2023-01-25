class MinStack {
public:
    stack<int> elementStack;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(elementStack.empty() || elementStack.top() > val){
                elementStack.push(val);
            
        }
        else {
            elementStack.push(elementStack.top());
        }
        minStack.push(val);
    }
    
    void pop() {
        elementStack.pop();
        minStack.pop();
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return elementStack.top();
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