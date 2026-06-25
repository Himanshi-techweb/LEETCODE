class Solution {
public:
 
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> arr(n);
        vector<int> lis;
        for(int i=0;i<obstacles.size();i++){
            int ix=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
            if(ix==lis.size()){
                lis.push_back(obstacles[i]);
            }
            else{
                lis[ix]=obstacles[i];
            }
            arr[i]=ix+1;
        }
        return arr;
    }
};