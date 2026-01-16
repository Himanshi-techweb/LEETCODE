class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hs, vector<int>& vs) {
       hs.push_back(m);hs.push_back(1);
       vs.push_back(n);vs.push_back(1);
       sort(hs.begin(),hs.end());
       sort(vs.begin(),vs.end());
       unordered_set<int> h;
       unordered_set<int> v;
       long long ans=-1;
       int MOD =1e9 +7;
       int hssize=hs.size();
       int vssize=vs.size();
       for(int i=0;i<hssize;i++){
        for(int j=i+1;j<hssize;j++){
          h.insert(hs[j]-hs[i]);
        }
       }

       for(int i=0;i<vssize;i++){
        for(int j=i+1;j<vssize;j++){
          v.insert(vs[j]-vs[i]);
        }
       }

        for(auto it:h){
            if(v.find(it)!=v.end()){
                ans=max(ans,((long long)it*it));
            }
        }
        return ans%MOD;
    }
};