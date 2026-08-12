class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};

    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx < 0 || sy < 0) {
            return false;
        }

        if(t == 0) {
            return sx == fx && sy == fy;
        }

        for(auto &dir : directions) {
            int sx_ = sx + dir[0];
            int sy_ = sy + dir[1];

            if(isReachableAtTime(sx_, sy_, fx, fy, t-1))
                return true;
        }

        return false;

    }
};

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int vert_dist = abs(sy-fy);
        int hor_dist  = abs(sx-fx);

        if(vert_dist == 0 && hor_dist == 0 && t == 1) {
            return false;
        }

        return t >= max(vert_dist, hor_dist);

    }
};
