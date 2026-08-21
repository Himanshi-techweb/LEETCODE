class MinStack {
public:
    stack<int> st;
    vector<int> arr;
    MinStack() {
        arr={};
    }
    
    void push(int value) {
       st.push(value);
       if(arr.size()==0 || arr.back()>=value){
           arr.push_back(value);
       } 
    }
    
    void pop() {
        int t=st.top();
        if(t==arr.back())arr.pop_back();
        st.pop();
    }
    
    int top() {
       return st.top(); 
    }
    
    int getMin() {
       if(arr.size()==0 )return -1;
       return arr.back(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */