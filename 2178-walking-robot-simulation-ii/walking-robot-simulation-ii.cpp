// class Robot {
// public:
//     Robot(int width, int height) {
        
//     }
    
//     void step(int num) {
        
//     }
    
//     vector<int> getPos() {
        
//     }
    
//     string getDir() {
        
//     }
// };

// /**
//  * Your Robot object will be instantiated and called as such:
//  * Robot* obj = new Robot(width, height);
//  * obj->step(num);
//  * vector<int> param_2 = obj->getPos();
//  * string param_3 = obj->getDir();
//  */
class Robot {
    int w, h, perimeter;
    int currPos = 0;
    bool moved = false;
    vector<pair<vector<int>, string>> path;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h) - 4;

        // Precompute the perimeter path
        // East boundary
        for (int i = 0; i < w; i++) path.push_back({{i, 0}, "East"});
        // North boundary
        for (int i = 1; i < h; i++) path.push_back({{w - 1, i}, "North"});
        // West boundary
        for (int i = w - 2; i >= 0; i--) path.push_back({{i, h - 1}, "West"});
        // South boundary
        for (int i = h - 2; i > 0; i--) path.push_back({{0, i}, "South"});
    }
    
    void step(int num) {
        moved = true;
        currPos = (currPos + num) % perimeter;
    }
    
    vector<int> getPos() {
        return path[currPos].first;
    }
    
    string getDir() {
        // Special case: if at (0,0) after moving, direction is South
        if (moved && currPos == 0) return "South";
        return path[currPos].second;
    }
};