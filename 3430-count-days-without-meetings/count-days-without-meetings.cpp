class Solution {
public:
    // vector<vector<int> > mergeinterval(vector<vector<int>>& arr){
    //     sort(arr.begin(),arr.end());
    //     vector<vector<int>> ans;
    //     int i=0;
    //     while(i<arr.size()){

    //     }
    // }
    int countDays(int days, vector<vector<int>>& meetings) {
        // vector<int> arr(days+1,0);
        if (meetings.empty()) return days; 
        sort(meetings.begin(), meetings.end());

        int occupiedDays = 0, prevStart = -1, prevEnd = -1;

        for (auto& meet : meetings) {
            int start = meet[0], end = meet[1];

            if (start > prevEnd) { 
                occupiedDays += (end - start + 1);
                prevStart = start;
                prevEnd = end;
            } else if (end > prevEnd) {  
                occupiedDays += (end - prevEnd);
                prevEnd = end;
            }
        }

        return days - occupiedDays;  

    }
};