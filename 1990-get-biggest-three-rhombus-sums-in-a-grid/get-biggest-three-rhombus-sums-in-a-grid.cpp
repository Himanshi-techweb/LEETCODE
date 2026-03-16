class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
    //    priority_queue<int,vector<int> ,greater<int>> q;
    priority_queue<int>q;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //for each index check sum 
           q.push(grid[i][j]);
            int k=1;
            //check k if it correct
            for(;;k++){
                if(i+2*k>=m)break;
                if(j-k<0)break;
                if(j+k>=n)break;
  
                int sum=0;
                for(int t=0;t<k;t++)sum+=grid[i+t][j+t];
                for(int t=0;t<k;t++)sum+=grid[i+k+t][j+k-t];
                for(int t=0;t<k;t++)sum+=grid[i+2*k-t][j-t];
                for(int t=0;t<k;t++)sum+=grid[i+k-t][j-k+t];

                q.push(sum);
                cout<<sum<<endl;
            }

            //check sum in 
            
        }
       } 
       vector<int> ans;
       int k=0;
       set<int> st;
       while(!q.empty()){
        // if(ans.empty())ans.push_back(q.top());
        // else if(!ans.empty() && ans.back()!=q.top()){
        //    ans.push_back(q.top());
        // }
        // q.pop();
        st.insert(q.top());
        q.pop();
        if(st.size()==3)break;
       }
       for(auto it:st)ans.push_back(it);
       reverse(ans.begin(),ans.end());
       return ans;
    }
};