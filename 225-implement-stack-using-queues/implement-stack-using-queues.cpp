class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
      q.push(x);
      int size=q.size();
      while(size>1){
        q.push(q.front());
        q.pop();
        size--;
      }
    }
    
    int pop() {
      if(q.empty())return -1;
      int w=q.front();
      q.pop();
      return w; 
    }
    
    int top() {
      if(q.empty())return -1;
      return q.front();  
    }
    
    bool empty() {
     return q.empty();   
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */