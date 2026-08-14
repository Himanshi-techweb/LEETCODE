class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int ans=0;
        // vector<int> arr(26,0);
        for(int i=0;i<s.size();i++){
            vector<int> arr(26,0);
            for(int j=i;j<s.size();j++){
                arr[s[j]-'a']++;
                cout<<i<<" "<<j<<" "<<j-i+1<<endl;
                char ch=s[j];
                if(arr[ch-'a']>2)break;
                
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};