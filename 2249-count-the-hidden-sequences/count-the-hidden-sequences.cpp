class Solution {
public:
    int numberOfArrays(vector<int>& difference, int lower, int upper) {
       long long  mini=0;
       long long  maxi=0;
       long long curr=0;
       for(auto x:difference){
        curr+=x;
        mini=min(mini,curr);
        maxi=max(maxi,curr);
       } 
       if(upper-lower<(maxi-mini))return 0;
       return ((upper-lower)-(maxi-mini)+1);
    }
};