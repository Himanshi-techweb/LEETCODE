class Solution {
public:
    bool hasAllCodes(string s, int k) {
       int size=pow(2,k);
       vector<int> arr(size,0);
       for(int i=0;i<s.size();i++){
            int decimal=0;
            if(i+k>s.size())break;
            for(int j=i;j<i+k;j++){
                decimal=decimal * 2 + (s[j]-'0');
            }
            arr[decimal]=1;
       }

       for(int i=0;i<arr.size();i++)if(arr[i]==0){
        cout<<i<<" "<<arr[i]<<endl;
        return false;
       }
       return true;
    }
};