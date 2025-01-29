class FindSumPairs {
public:
    vector<int>arr1;vector<int>arr2;
    unordered_map<int,int> check;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
       arr1=nums1;
       arr2=nums2;
       for(auto x:arr2){
          check[x]++;
       } 
    }
    
    void add(int index, int val) {
      check[arr2[index]]--;
      arr2[index]+=val;
      check[arr2[index]]++;
    }
    
    int count(int tot) {
       int m=arr1.size();
       int ans=0;
       for(int i=0;i<m;i++){
          int temp=tot-arr1[i];
          if(check.find(temp)!=check.end()){
            ans=ans+check[temp];
          }
       }  
       return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */