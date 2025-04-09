class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
     unordered_set<int> q;
     for(auto x: arr){
        if(x<k)return -1;
        else if(x==k) continue;
        else q.insert(x);
     }
     return q.size();
    }
};