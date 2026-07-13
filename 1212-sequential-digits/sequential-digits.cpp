class Solution {
public:

    void solve(int i,string str,vector<int> &ans,int high,int low){
        long long num=stoll(str);
        // base case
        if( i>=str.size() && num>=low && num<=high){
            ans.push_back(num);
            // return;
        }
        //
        char prev=str[i-1];
        if(prev=='9')return;
        if(i==str.size()){
            str+=(((prev-'0')+1)+'0');
        }
        else{
            str[i]=(((prev-'0')+1)+'0');
        }
        solve(i+1,str,ans,high,low);

    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string l=to_string(low);
        char ch=l[0];
        //fix strt that 0 index and then try to change later digit
        for(int k='1';k<='9';k++){
            l[0]=k;
            solve(1,l,ans,high,low);

        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};