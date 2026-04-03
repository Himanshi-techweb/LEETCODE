class Solution {
public:
    // unordered_map<int,int> rob_dist;int m;
    
    // int maxwall(int i,vector<int> &robots,vector<int> &walls,unordered_set<int> st;){
    //     if(i==m)return 0;

    //     //calculate left and right range
    //     int left=robots[i]-rob_dist[robots[i]];
    //     int right=robots[i]+rob_dist[robots[i]];
    //     if(i>0)left=max(left,robots[i-1]);
    //     if(i<m-1)right=min(right,robots[i+1]);
    //     int lw=lower_bound(walls.begin(),walls.end(),left)-walls.begin();
    //     int rw=upper_bound(walls.begin(),walls.end(),right)-walls.begin();
    //     //now each robot has two option it move left or right if 
    //     //if left then all walls from curr to lw and mark it as break in st
    //     int left_count=0;
    //     int k=rob_dis[robots[i]];
    //     while(lw<=k){
    //         if(st.count(walls[k])){

    //         }
    //     }

    //     //if right then all walls from from curr to rw and mark it as break in st
    //     int right_count=0;


    //     return max(left_count,right_count);
    // }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        // m=robots.size();
        // for(int i=0;i<m;i++){
        //     rob_dist[robots[i]]=distance[i];
        // }
        // sort(robots.begin(),robots.end());
        // sort(walls.begin(),walls.end());
        // vector<int> pos()



        int n = robots.size();
      
        // Create pairs of (robot_position, robot_distance) for easier handling
        vector<pair<int, int>> robotInfo(n);
        for (int i = 0; i < n; i++) {
            robotInfo[i] = {robots[i], distance[i]};
        }
      
        // Sort robots by their positions
        ranges::sort(robotInfo, {}, &pair<int, int>::first);
      
        // Sort walls for binary search
        ranges::sort(walls);
      
        // DP memoization table
        // dp[i][direction]: maximum walls destroyed considering robots 0 to i
        // direction = 0: robot i moves left, direction = 1: robot i moves right
        vector<vector<int>> dp(n, vector<int>(2, -1));
      
        // Recursive function with memoization
        auto solve = [&](this auto&& solve, int robotIdx, int prevDirection) -> int {
            // Base case: no robots left to consider
            if (robotIdx < 0) {
                return 0;
            }
          
            // Return memoized result if already computed
            if (dp[robotIdx][prevDirection] != -1) {
                return dp[robotIdx][prevDirection];
            }
          
            int maxDestroyed = 0;
          
            // Option 1: Current robot moves LEFT
            // Calculate the leftmost position this robot can reach
            int leftBound = robotInfo[robotIdx].first - robotInfo[robotIdx].second;
          
            // Ensure no overlap with previous robot (if exists)
            if (robotIdx > 0) {
                leftBound = max(leftBound, robotInfo[robotIdx - 1].first + 1);
            }
          
            // Count walls that can be destroyed when moving left
            int leftWallIdx = ranges::lower_bound(walls, leftBound) - walls.begin();
            int rightWallIdx = ranges::lower_bound(walls, robotInfo[robotIdx].first + 1) - walls.begin();
            int wallsDestroyedLeft = rightWallIdx - leftWallIdx;
          
            // Recurse for previous robots (current robot chose left, so prev can choose any direction)
            maxDestroyed = solve(robotIdx - 1, 0) + wallsDestroyedLeft;
          
            // Option 2: Current robot moves RIGHT
            // Calculate the rightmost position this robot can reach
            int rightBound = robotInfo[robotIdx].first + robotInfo[robotIdx].second;
          
            // Ensure no overlap with next robot (if exists)
            if (robotIdx + 1 < n) {
                if (prevDirection == 0) {
                    // If next robot will move left, consider its leftmost reach
                    rightBound = min(rightBound, robotInfo[robotIdx + 1].first - robotInfo[robotIdx + 1].second - 1);
                } else {
                    // If next robot will move right, just avoid its starting position
                    rightBound = min(rightBound, robotInfo[robotIdx + 1].first - 1);
                }
            }
          
            // Count walls that can be destroyed when moving right
            leftWallIdx = ranges::lower_bound(walls, robotInfo[robotIdx].first) - walls.begin();
            rightWallIdx = ranges::lower_bound(walls, rightBound + 1) - walls.begin();
            int wallsDestroyedRight = rightWallIdx - leftWallIdx;
          
            // Recurse for previous robots (current robot chose right, so pass direction = 1)
            maxDestroyed = max(maxDestroyed, solve(robotIdx - 1, 1) + wallsDestroyedRight);
          
            // Store and return the result
            dp[robotIdx][prevDirection] = maxDestroyed;
            return maxDestroyed;
        };
      
        // Start solving from the last robot, assuming it moves right
        // (The last robot's direction doesn't affect next robots since there are none)
        return solve(n - 1, 1);
    }
};