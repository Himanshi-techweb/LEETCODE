class Solution {
public:
    static bool comparator(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& num) {
        sort(num.begin(),num.end(),comparator);
        int cnt=0;
        int before=INT_MIN;
        int i=0;
        while(i<num.size()){
            if(num[i][0]>=before){
                cnt++;
                before=num[i][1];
            }
            i++;
        }
        return num.size()-cnt;

        
    }
};