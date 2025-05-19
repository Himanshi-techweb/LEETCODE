class Solution {
public:
    string triangleType(vector<int>& arr) {
       
       if(arr[0]+arr[1]<=arr[2] || arr[1]+arr[2]<=arr[0] || arr[0]+arr[2]<=arr[1])return "none";
       else if(arr[0]==arr[1] && arr[1]==arr[2])return "equilateral";
       else if(arr[1]==arr[0] || arr[1]==arr[2] || arr[0]==arr[2])return "isosceles";
       else return "scalene";
    }
};