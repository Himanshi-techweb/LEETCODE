class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> arr=asteroids;
        vector<int> ans;
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0 )st.push(arr[i]);
            else if(!st.empty() && st.top()>0){//arr[i] is negative
              while(!st.empty() && st.top() >0 && abs(arr[i])>st.top())st.pop(); 
              if(!st.empty() && st.top()==abs(arr[i])){
                st.pop();
              }
              else if(st.empty() || !st.empty() && st.top()<0)st.push(arr[i]);
            }
            else st.push(arr[i]);    
        } 
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};