class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& topRight) {
      //find intersection between two 
      // side of rectangle 
      // r1x1=bl[i][0]  r1x2=topRight[i][0]   r1y1=bl[i][1]  r1y2=topRight[i][1];
      // r2x1=bl[i+1][0]  r2x2=topRight[i+1][0]   r2y1=bl[i+1][1]  r2y2=topRight[i+1][1];
      //check flag only in x direction
      //as two loop are running no need to check  
      // case of intersection r1x2<=r2x1 && r1y2<=r2y1
      // then length_x=r2x1-r1x2 length_y =r2y1-r1y2
      //min of it will be length and area that mini*mini
      long long ans=0;
      for(int i=0;i<bl.size()-1;i++){
        for(int j=i+1;j<bl.size();j++){
            int r1x1=bl[i][0];int   r1x2=topRight[i][0];  int  r1y1=bl[i][1];int   r1y2=topRight[i][1];
            int r2x1=bl[j][0];  int r2x2=topRight[j][0];   int r2y1=bl[j][1];  int r2y2=topRight[j][1];
            if(r1x2>=r2x1 && r1y2>=r2y1 && r2x2>=r1x1 && r2y2>=r1y1){
            int length_x=min(r1x2,r2x2)-max(r2x1,r1x1);
            int length_y =min(r1y2,r2y2)-max(r2y1,r1y1);
            if(length_x>0 && length_y>0){
              int mini=min(length_x,length_y);
               ans=max(ans,(long long)mini*mini);
            }
            
         } 
        }
         
         
      }
      return ans;



    }
};