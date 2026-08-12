class Solution {
public:
    vector<vector<int>> rects;
    map<int, int> mp;
    int sum = 0;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int n = rects.size();

        for(int i = 0; i<n; i++) {
            int x1 = rects[i][0];
            int x2 = rects[i][2];
            int y1 = rects[i][1];
            int y2 = rects[i][3];

            sum += (x2-x1+1) * (y2-y1+1);

            mp[sum] = i;
        }
    }

    vector<int> pick() {
        int randomPoint = rand()%sum + 1;

        auto it       = mp.upper_bound(randomPoint);
        int rectIndex = it->second;

        int x1 = rects[rectIndex][0];
        int x2 = rects[rectIndex][2];
        int y1 = rects[rectIndex][1];
        int y2 = rects[rectIndex][3];

        int x = x1 + rand()%(x2-x1+1);
        int y = y1 + rand()%(y2-y1+1);

        return {x, y};
    }
};
