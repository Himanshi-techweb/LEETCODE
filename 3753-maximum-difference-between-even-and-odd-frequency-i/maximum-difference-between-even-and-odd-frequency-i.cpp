class Solution {
public:
    int maxDifference(string s) {
      int oddfreq=INT_MIN;int evenfreq=INT_MAX;
      map<char,int> freq;
      for(auto x:s){
        freq[x]++;
        
      }
      for(auto x:freq){
          if(x.second%2==0 ){
            evenfreq=min(evenfreq,x.second);
        }
          else{
            oddfreq=max(oddfreq,x.second);
        }
      }
      return (oddfreq-evenfreq);
    }
};