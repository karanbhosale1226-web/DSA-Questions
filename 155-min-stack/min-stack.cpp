#include <stack>
class MinStack {
public:
    stack<long long> s;
    long long mini;

    MinStack() {
        mini=0;
        
    }
    
    void push(long long value) {
        if(s.empty()){
            s.push(value);
            mini=value;
        }
        else{
            if(value<mini){
                long long val=2*value-mini;
                s.push(val);
                mini=value;
            }
            else{
                s.push(value);

            }
        }
        
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        long long curr=s.top();
        s.pop();
        if(curr<mini){
            mini=2*mini-curr;
        }
    }
    
    long long top() {
        if(s.empty()){
            return -1;
        }
        long long curr=s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
        
    }
    
    long long getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * long long param_3 = obj->top();
 * long long param_4 = obj->getMin();
 */