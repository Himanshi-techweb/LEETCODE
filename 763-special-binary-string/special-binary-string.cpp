class Solution {
public:
   
    string solve(string &s){

        vector<string> arr;
        int sum=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            sum+=(s[i]=='1'?1:-1);
            if(sum==0){
                string str=s.substr(start+1,i-start-1);
                start=i+1;
                str="1"+solve(str)+"0";
                arr.push_back(str);
            }
        }
        sort(arr.begin(),arr.end(),greater<string>());
        string result;
        for(auto it:arr){
            result=result+it;
        }
        return result;
    }
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};