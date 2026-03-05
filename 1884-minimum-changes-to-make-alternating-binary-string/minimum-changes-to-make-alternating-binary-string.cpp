class Solution {
public:
    int minOperations(string s) {
       //consider string start from 0;
       int count_0=0;int count_1=0;
       for(int i=0;i<s.size();i++){
        if(i%2==0){
            count_0+=(s[i]-'0'==0?0:1);
            count_1+=(s[i]-'0'==1?0:1);
        }
        else{
           count_0+=(s[i]-'0'==1?0:1); 
           count_1+=(s[i]-'0'==0?0:1);
        }
       } 

       //consider string start from 1;
    //    
    //    for(int i=0;i<s.size();i++){
    //     if(i%2==0){
            
    //     }
    //     else{
            
    //     }
    //    }


       return min(count_0,count_1); 
    }
};