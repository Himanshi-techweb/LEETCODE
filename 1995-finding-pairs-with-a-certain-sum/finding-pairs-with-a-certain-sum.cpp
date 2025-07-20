class FindSumPairs {
public:
    vector<int> a;vector<int> b;
    unordered_map<long long,long long> check;
    FindSumPairs(vector<int>& x, vector<int>& y) {
        
      for(auto it:x)a.push_back(it); 
      for(auto it:y)b.push_back(it); 
      for(auto it:b){
        check[it]++;
      } 
    }
    
    void add(int index, int val) {
       if(index<b.size()){
        check[b[index]]--;
        b[index]+=val;
        check[b[index]]++;
       } 
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<a.size();i++){
        int y=a[i];
        int x=tot-y;
           if(x>=0 && check.find(x)!=check.end()){
                cnt=cnt+check[x];
           }
        }
      return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */