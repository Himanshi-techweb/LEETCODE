class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m=mat.size();int n=mat[0].size();
       int lowr=0;int lowc=0;
       int highr=m-1;int highc= n-1;
    //    while(lowr<=highr && lowc<=highc){
    //     int midr=(lowr+highr)>>1;
    //     int midc=(lowc+highc)>>1;
    //     if(mat[midr][midc]==tar){
    //        return true;
    //     }
    //     else if (mat[midr][midc]>tar){
    //         if(midc==0 ){
    //             if(midr>)highr=midr-1;
    //             highc=n-1;
    //         }
    //         else highc=midc-1;
    //         highr=midr;
    //     }
    //     else{
    //         if(midc==n-1){
    //            lowc=0;
    //            if(midr<m-1)lowr=midr+1;
    //         }
    //         else lowc=midc+1;
    //         lowr=midr;
    //     }
    //    }
    while (lowr <= highr && lowc <= highc) {
        int midr = (lowr + highr) / 2;
        int midc = (lowc + highc) / 2;
        
        if (mat[midr][midc] == tar) {
            return true;
        }
        else if (mat[midr][midc] < tar) {
            // Move right or down
            if (midc < highc) {
                lowc = midc + 1;
            } else {
                lowr = midr + 1;
                lowc = 0;     // reset column range
                highc = n - 1;
            }
        }
        else {
            // Move left or up
            if (midc > lowc) {
                highc = midc - 1;
            } else {
                highr = midr - 1;
                lowc = 0;     // reset column range
                highc = n - 1;
            }
        }
    }
       return false;
    }
};