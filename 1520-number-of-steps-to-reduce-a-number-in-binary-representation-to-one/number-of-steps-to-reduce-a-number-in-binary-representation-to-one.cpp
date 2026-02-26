class Solution {
public:
    // odd only when count of 1 greater than 1 and s[0]==1 then odd otherwise even 
    // int check(string s){
    //     reverse(s.begin(),s.end());
    //     int num=0;int count=0;
    //     for(int i=0;i<s.size();i++){
    //       num=num+(s[i]-'0')*(1<<count);
    //       count++;
    //     }
    //     return num;
    // }
    // string binary(int n){
    //     string s="";
    //     while(n>0){
    //         int rem=n%2;
    //         s+=(rem+'0');
    //         n=n/2;

    //     }
    //     reverse(s.begin(),s.end());
    //     return s;
    // }
    void add(string &s){
        //add 1
        for(int i=s.size()-1;i>=0;i--){
          if(s[i]=='1')s[i]='0';
          else {
            s[i]='1';
            return;
          }  
        }
        s='1'+s;    
    }
    int check(string &s){
        int count=0;
        for(int i=0;i<s.size();i++)if(s[i]=='1')count++;
        return count;
    }
    int numSteps(string s) {
        int x=0;
        while(check(s)>=1){
           int count =check(s);
           //odd;
           if(count==1){
            //check answer 
            if(s[s.size()-1]=='1')return x;
            else {
                //right shift
                s.pop_back();
                s='0'+s;
            } 
           }
           else if(count>1){
              if(s[s.size()-1]=='1'){
                //odd then add 1 
                add(s);
              }
              else{
                s.pop_back();
                s='0'+s;
              }
           }
           x++;
        }
        return x;
    }
};