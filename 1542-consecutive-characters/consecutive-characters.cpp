class Solution {
public:
    int maxPower(string s) {
     int i=0;int j=1;
     int prev=-1;
     int count=0;
     int ans=INT_MIN;
     while(i<s.length()){
       if(s[i]==s[j]){
        j++;
        count++;
       }
       else{
        if(i!=prev){
            ans=max(ans,count);
            count=0;
        }
        prev=i;
        i++;
        j=i+1;
       }  
     }
     return ans+1;   
    }
};