class Solution {
public:
    int n;
    vector<vector<int>> t;

    int solve(int idx, vector<int> &heights, int bricks, int ladders) {
        if(idx == n - 1)
            return 0;

        if(t[bricks][ladders] != -1)
            return t[bricks][ladders];

        if(heights[idx] >= heights[idx + 1]) {
            t[bricks][ladders] = 1 + solve(idx+1, heights, bricks, ladders);
        } else {

            int byBrick  = 0;
            int byLadder = 0;
            if(bricks >= heights[idx + 1] - heights[idx])
                byBrick  = 1 + solve(idx+1, heights, bricks - (heights[idx+1] - heights[idx]), ladders);

            if(ladders > 0)
                byLadder = 1 + solve(idx+1, heights, bricks, ladders - 1);

            t[bricks][ladders] = max(byBrick, byLadder);
        }

        return t[bricks][ladders];
    }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size();

        t = vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1));

        return solve(0, heights, bricks, ladders);
    }
};
