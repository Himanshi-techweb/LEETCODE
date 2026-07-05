class Solution {
public:
    int n,m;
    unordered_map<long long,long long> st;
    long long solve(int i,int j,int prev,vector<int> &arr,vector<int> &num){
        
        if(i==n){
            if(j==m)return 0;
            else return INT_MAX;
        }
        if(j==m)return INT_MAX;
        if((prev & arr[i]) < num[j])return INT_MAX;

        // string key=to_string(i) +"#"+to_string(j)+"#"+to_string(prev);
        long long key=((long long)i<<40)| ((long long)j<<32)| prev;
        if(st.count(key))return st[key];
        long long newbegin=INT_MAX;

        //option 2
        //if equal then 1)start new subarray or 2)continue current subarray only
        if((arr[i]&prev)==num[j]){
            newbegin=arr[i] + solve(i+1,j+1,INT_MAX,arr,num);
        }
        //option 1
        //take it to curr subarray and take and with back subarray element
        long long curr=solve(i+1,j,arr[i] & prev,arr,num);
        return st[key]=min(curr,newbegin);
        
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n=nums.size();m=andValues.size();
        long long ans= solve(0,0,INT_MAX,nums,andValues);
        return ans==INT_MAX?-1:ans;
    }
};