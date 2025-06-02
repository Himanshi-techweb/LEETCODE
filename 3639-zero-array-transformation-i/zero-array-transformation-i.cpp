// class Solution {
// public:
//     bool isZeroArray(vector<int>& arr, vector<vector<int>>& queries) {
//        for(int i=0;i<queries.size();i++){
//         //vector<int> check=;
//         for(int j=queries[i][0];j<=queries[i][1];j++){
//            arr[j]=max(0,arr[j]-1); 
//         }
//        }
//        for(auto x:arr){
//         if(x!=0)return false;
//        }
//        return true; 
//     }
// };
class Solution {
public:
    bool isZeroArray(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> diff(n + 1, 0); // one extra for boundary condition

        // Apply range updates using a difference array
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l] -= 1;
            if (r + 1 < n) {
                diff[r + 1] += 1;
            }
        }

        // Apply the difference array to original array
        int delta = 0;
        for (int i = 0; i < n; ++i) {
            delta += diff[i];
            arr[i] = max(0, arr[i] + delta); // delta is negative
            if (arr[i] != 0) return false;   // early exit if not zero
        }

        return true;
    }
};
