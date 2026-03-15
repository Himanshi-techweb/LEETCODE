class Fancy {
public: 
     const int MOD=1e9 +7;
    // queue<pair<int,char>> cal;
    // vector<long long> arr;
    // long long add=0;long long mul=1;
    // Fancy() {
    //    arr={}; 
    // }
    // // long long inverse(int val){
    // //     int inv=
    // // }
    // void append(int val) {
    //    int x=((val-add+MOD)%MOD )/mul;
    //    arr.push_back(x);
    // }
    
    // void addAll(int inc) {
    //    add=(add*mul)%MOD;
    // }
    
    // void multAll(int m) {
    //    add=(add*m)%MOD;
    //    mul=(mul*m)%MOD; 
    // }
    
    // int getIndex(int idx) {
    //     if(idx>=arr.size())return -1;
    //     return (arr[idx]*mul +add)%MOD;
        
    // }
    vector<long long> arr;
    long long mul = 1, add = 0;

    long long modInverse(long long x){
        long long res=1,p=MOD-2;
        while(p){
            if(p&1) res=res*x%MOD;
            x=x*x%MOD;
            p>>=1;
        }
        return res;
    }

    void append(int val){
        long long inv = modInverse(mul);
        long long x = ((val - add + MOD) % MOD * inv) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc){
        add = (add + inc) % MOD;
    }

    void multAll(int m){
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx){
        if(idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */