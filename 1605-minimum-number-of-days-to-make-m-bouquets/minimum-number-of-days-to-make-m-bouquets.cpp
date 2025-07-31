class Solution {
public:
    bool check(long long mid,int m,int k,vector<int> &Day){
        int cnt=0;int f_cnt=0;
        for(int i=0;i<Day.size();i++){
           if(Day[i]<=mid){
            f_cnt++;
           }
           else{
            cnt+=(f_cnt/k);
            f_cnt=0;
           }
        }
        if(f_cnt>0){
            cnt+=(f_cnt/k);
        }
        return cnt>=m;
    }
    int minDays(vector<int>& Day, int m, int k) {
       if(Day.size()/k<m)return -1;
       int low=1;int high=*max_element(Day.begin(),Day.end());
       int ans=-1;
       while(low<=high){
        long long mid=low+(high-low)/2;
        if(check(mid,m,k,Day)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
       }
       return ans; 
    }
};