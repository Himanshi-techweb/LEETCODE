class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            //if st not empty and top is same as 
            int t=asteroids[i];
            //if empty or both number of same sign then push it 
            if(st.empty() || (t>0 && st.top()>0) || (t<0 && st.top()<0))st.push(t);
            else if(!st.empty() && st.top()>0 && abs(t)==st.top())st.pop();
            else {
                while(!st.empty() && st.top()>0 && t<0 && abs(t)>st.top())st.pop();
                if(!st.empty() && st.top()>0 && t<0 && abs(t)==st.top())st.pop();
                // if(!st.empty() && abs(t)<st.top() || )continue;
                else if(st.empty() || st.top()>0 && t>0 || st.top()<0 && t<0 || st.top()<0 && t>0)st.push(t);
            }

            

        }
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};