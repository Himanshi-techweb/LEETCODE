class Solution {
public:
    int reverseBits(int n) {
      uint32_t r=0;
      int i=0;
      while(i<32){
        r=r<<1;
        r= r | (n&1);
        n=n>>1;
        i++;
      }  
      return r;
    }
};