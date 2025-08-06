class Solution {
public:
    int maxlen=0;
    int solve(int i,int diff,vector<int> &arr,unordered_map<int,unordered_map<int,int>> &check){
        if(i>=arr.size()){
            if(diff==0)return 0;else return INT_MIN;
        }
        // string key=to_string(i)+','+to_string(l1)+','+to_string(l2);
        if(check[i][diff])return check[i][diff];
        //three option for index to take
        //take in l1 not in l2
        int take_left=0;int take_right=0;int nottake=0;
        take_left=arr[i]+solve(i+1,diff+arr[i],arr,check);//(l1+arr[i])-(l2)
        take_right=arr[i]+solve(i+1,diff-arr[i],arr,check);//(l1)-(l2+arr[i])
        nottake=solve(i+1,diff,arr,check);
        return check[i][diff]=max({take_left,take_right,nottake});
    }
    int tallestBillboard(vector<int>& rods) {
        int l1=0;int l2=0;
        unordered_map<int,unordered_map<int,int>> check;
        // vector<vector<vector<int>>> check(rods.size(),vector<vector<int>> (5001,vector<int>(5001,-1)));
        return solve(0,0,rods,check)/2;
    }
};