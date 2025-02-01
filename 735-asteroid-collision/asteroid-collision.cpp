class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
      stack<int> st;
      for(auto x:arr){
        bool destroy=false;
        while(!st.empty() && x<0 && st.top()>0){
           // if smaller then current
           if(st.top()<-x){
            st.pop();
           }
           else if(st.top()==-x){
            st.pop();
            destroy=true;
            break;
           }
           else{
            destroy=true;
            break;
           }
        }
        if(!destroy){
            st.push(x);
        }
      }
      vector<int>ans; 
      while(!st.empty()){
        (ans.push_back(st.top()));
        st.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};