class Solution {
public:
    bool hasAlternatingBits(int n) {
       //first check first left most bit in binary representation
       int x=(n&1);
       int curr=0;
       n=n>>1;
       while(n>0){
          //take xor of prev and curr bit if 1 ok if 0 then false
          curr=(n&1);
          if(curr^x==0)return false;
          x=curr;
          n=n>>1;
       }
       return true;
    //  vector<int> result;
    // while(n>0){
    //   int currrem=n%2;
    //   if(result.size()>=1 && (result.back() ^ currrem )== 0)return false;
    //   result.push_back(currrem); 
    //   n=n/2;
    // }
    // for(auto it:result)cout<<it<<" ";
    // return true;
    }
};