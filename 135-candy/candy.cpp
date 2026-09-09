class Solution {
public:
    int candy(vector<int>& ratings) {
        int cnt=1;
        vector<int> arr(ratings.size(),0);
        for(int i=1;i<ratings.size();){
            if(ratings[i]==ratings[i-1]){
                cnt++;
                arr[i]=cnt;
                i++;
                continue;

            }
            
            int peak=1;
            while(i<ratings.size() && ratings[i]>ratings[i-1]){
                peak+=1;
                cnt+=peak;
                arr[i]=cnt;
                i++;
            }
            int below=1;
            while(i<ratings.size() && ratings[i]<ratings[i-1]){
                
                cnt+=below;
                arr[i]=cnt;
                below++;
                i++;

            }
            if(below>peak)cnt=(cnt+below-peak);
        }
        for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
        return cnt;
    }
};