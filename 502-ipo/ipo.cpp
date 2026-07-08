struct cmp{
     bool operator()(const vector<int>&a,const vector<int>&b)const{
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]>b[0];
     }
};
class Solution {
public:
    // bool cmp(const vector<int>&a,vector<int>&b){
    //     if(a[0]==b[0])return a[1]>b[1];
    //     return a[0]<b[0];
    // }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> arr;
        for(int i=0;i<capital.size();i++){
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());
        int ans=w;int i=0;
        priority_queue<int>q;
        while(k>0){

            while(i<arr.size() && arr[i][0]<=w ){
                q.push(arr[i][1]);
                i++;
            }//insert all less than or equal to w
            if(q.empty())break;
            auto front=q.top();
            q.pop();
            w+=front;
            ans+=front;
            k--;
            

        }
        return ans;
    }
};