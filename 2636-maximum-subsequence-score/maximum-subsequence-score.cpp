class Solution {
public:
    // long long solve(int i,int k,vector<int>&arr1,vector<int>&arr2,int mini){
    //     if(k==0)return 0;
    //     if(i>=arr1.size())return LLONG_MIN;

    //     //take that number 
    //     int mini_=min(mini,arr2[i]);
    //     long long take=arr1[i] + solve(i+1,k-1,arr1,arr2,mini_) ;
    //     take=mini_*take*1LL;
        
    //     long long nottake=solve(i+1,k,arr1,arr2,mini);
    //     return max(take,nottake);
    // }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // return solve(0,k,nums1,nums2,INT_MAX);


        vector<pair<int,int>> arr;
        for(int i=0;i<nums1.size();i++){
            arr.push_back({nums2[i],nums1[i]});
        }


        auto lamba =[&](auto &x,auto &y){
            return x.first>y.first;
        };
        sort(arr.begin(),arr.end(),lamba);
        priority_queue<int,vector<int>,greater<int>>q;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i].second;
            q.push(arr[i].second);
        }
        long long res=sum*arr[k-1].first;
        //try from k to n
        for(int j=k;j<nums1.size();j++){
            sum+=arr[j].second;
            sum-=q.top();
            q.pop();
            q.push(arr[j].second);
            res=max(res,sum*arr[j].first);
        }
        return res;

    }
};