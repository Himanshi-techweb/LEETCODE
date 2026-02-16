class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        string str;
        while(i>=0 || j>=0 || carry){
            int ai=(i>=0 )?a[i]-'0':0;
            int bi=(j>=0)?b[j]-'0':0;
            int sum=(ai^bi^carry);
            carry=((ai^bi)&carry) | (ai&bi);
            str.push_back(sum+'0');
            i--;
            j--; 
        }
        reverse(str.begin(),str.end());
        return str;
    }
};