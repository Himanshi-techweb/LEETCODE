class Solution {
public:
     //1 2 3 4 5
    //stop condition will be when all are moving in same direction 
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // stack<int> st;
        // unordered_map<int,char> pos;
        // vector<pair<int,int>> arr;
        // for(int i=0;i<positions.size();i++){
        //     arr.push_back({positions[i],directions[i]});
        //     positions[i]=directions[i];
        // }
        // sort(arr.begin(),arr.end());
        // stack<int> st;
        // for(int i=0;i<arr.size();i++){
        //     if(pos[arr[i].first]==)
        // }
        int n = positions.size();
    
    vector<tuple<int,int,char,int>> robots;
    for(int i=0;i<n;i++){
        robots.push_back({positions[i], healths[i], directions[i], i});
    }

    sort(robots.begin(), robots.end());

    stack<int> st; // store indices in robots

    for(int i=0;i<n;i++){
        auto &[pos, h, dir, idx] = robots[i];

        if(dir == 'R'){
            st.push(i);
        } else {
            while(!st.empty() && get<2>(robots[st.top()]) == 'R' && h > 0){
                if(get<1>(robots[st.top()]) == h){
                    get<1>(robots[st.top()]) = 0;
                    h = 0;
                    st.pop();
                    break;
                }
                else if(get<1>(robots[st.top()]) > h){
                    get<1>(robots[st.top()])--;
                    h = 0;
                    break;
                }
                else{
                    h--;
                    get<1>(robots[st.top()]) = 0;
                    st.pop();
                }
            }
            get<1>(robots[i]) = h;
        }
    }

    vector<int> res(n, 0);
    for(auto &[pos,h,dir,idx]:robots){
        if(h > 0) res[idx] = h;
    }

    vector<int> ans;
    for(int i=0;i<n;i++){
        if(res[i] > 0) ans.push_back(res[i]);
    }

    return ans;

        

        
    }
};