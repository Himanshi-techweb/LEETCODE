class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        arr[1]=1;
        int i2=1;int i3=1;int i5=1;
        for(int i=2;i<=n;i++){
            int i2ugly=arr[i2]*2;
            int i3ugly=arr[i3]*3;
            int i5ugly=arr[i5]*5;
            int mini=min({i2ugly,i3ugly,i5ugly});
            arr[i]=mini;
            if(mini==i2ugly)i2++;
            if(mini==i3ugly)i3++;
            if(mini==i5ugly)i5++;
        }
        return arr[n];
    }
};