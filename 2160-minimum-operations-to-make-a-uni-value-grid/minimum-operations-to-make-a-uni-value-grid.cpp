class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int k) {

        vector<int> arr;
        for(auto x:grid){
            for(auto y:x){
                arr.push_back(y);
            }
        }
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int bet1=arr[n/2];
        
        int ans=INT_MAX;
        bool flag=true;
        int count=0;
        //try for bet1
        for(int i=0;i<n;i++){
            int x=abs(arr[i]-bet1)%k;
            if(x!=0){
                flag=false;
                count=INT_MAX;
                break;
            }
            count+=((abs(arr[i]-bet1)/k));
        }
        if(flag)ans=min(ans,count);
        count=0;
        if(!flag && n>1){
            int bet2=arr[(n/2)+1];
            for(int i=0;i<n;i++){
                int x=abs(arr[i]-bet2)%k;
                if(x!=0){
                    flag=false;
                    count=INT_MAX;
                    break;
                }
                count+=(abs(arr[i]-bet2)/k);
            }
        }
        // 
        if(ans==INT_MAX)return -1;
        return ans;
        
    }


};