class Solution {
public:
    vector<int> hour={1,2,4,8};
    vector<int> minute={1,2,4,8,16,32,64};
    vector<string> ans;
    void solve(int m,int currcount,int actualcount,int hourcount,int minutecount){
        if(currcount>actualcount){
            return;
        }
        if(m>10)return;
        if(currcount==actualcount){
            if(hourcount<=11 && minutecount<=59){
                string str=to_string(hourcount)+':';
                if(minutecount<10){
                    str+='0';
                }
                str+=to_string(minutecount);
                ans.push_back(str);
                // ans.push_back(hourcount+":"+minutecount);
                return;
            }
            
        }
        //include current index 
        if(m<4){
           solve(m+1,currcount+1,actualcount,hourcount+(1<<m),minutecount);
        }
        else{
            solve(m+1,currcount+1,actualcount,hourcount,minutecount+(1<<(m-4)));
        }

        solve(m+1,currcount,actualcount,hourcount,minutecount);
        
    }
    vector<string> readBinaryWatch(int turnedOn) {
        // vector<string> ans;
        solve(0,0,turnedOn,0,0);
        return ans;
    }
};