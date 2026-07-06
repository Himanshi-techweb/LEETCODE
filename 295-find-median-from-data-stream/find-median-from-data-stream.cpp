class MedianFinder {
public:
    vector<int> arr;
    int n;
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    MedianFinder() {
        n=-1;
    }
    
    void addNum(int num) {
        if(n==-1){
            maxi.push(num);
            n=1;
        }

        else{
            if(maxi.top()<num){
                mini.push(num);
                
            }
            else{
                maxi.push(num);
                
            }
            n++;
            int count=n/2;
            if(n%2!=0){
               count++; 
            }

            while(maxi.size()!=count){
                if(maxi.size()>count){
                    mini.push(maxi.top());
                    maxi.pop();
                }
                if(maxi.size()<count){
                    maxi.push(mini.top());
                    mini.pop();
                }
            }
        }
    }
    double findMedian() {
        // if(n==1)return maxi.top(); 
        if(n%2==0){
            return (double(maxi.top())+mini.top())/2.0;
        }
        else return maxi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */