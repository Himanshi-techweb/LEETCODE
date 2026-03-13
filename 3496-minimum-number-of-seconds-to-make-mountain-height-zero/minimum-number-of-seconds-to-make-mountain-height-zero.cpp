class Solution {
public:
    bool check(long long mid,vector<int> w,int h){
        //check if count of height is equal 
        long long total=0;
        for(int i=0;i<w.size();i++){
            int j = (sqrt(1 + 8.0 * mid / w[i]) - 1) / 2;
            total+=j;
        }
        
        cout<<(total>=h)<<endl;
        return total>=h;
    }
    long long minNumberOfSeconds(int mh, vector<int>& workerTimes) {
        long long low=1;
        long long high=0;
        long long ans=0;
        long long maxi=*max_element(workerTimes.begin(),workerTimes.end()); 
        for(int i=1;i<=mh;i++){
            high=high+(long long)maxi*i;
        }
        while(low<=high){
            long long mid=(low+high)/2;
            if(check(mid,workerTimes,mh)){
               high=mid-1;
               ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};