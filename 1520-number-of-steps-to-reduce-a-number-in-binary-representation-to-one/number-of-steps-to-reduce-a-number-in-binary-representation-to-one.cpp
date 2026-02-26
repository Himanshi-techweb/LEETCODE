class Solution {
public:
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
    int numSteps(string s) {
        int x=0;
        while(s!="1"){
           
           //odd;
           if(s.back()=='0')s.pop_back();
           else add(s);
           
           x++;
        }
        return x;
    }
};