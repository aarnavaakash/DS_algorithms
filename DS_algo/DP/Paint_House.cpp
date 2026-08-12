class Solution {
public:
    int minCost(vector<vector<int>> &costs) {

        int m = costs.size();
        if(m == 0)
            return 0;

        int n = 3;
        for(int row = 1; row < m; row++) {
             costs[row][0] += min(costs[row-1][1], costs[row-1][2]);
             costs[row][1] += min(costs[row-1][0], costs[row-1][2]);
             costs[row][2] += min(costs[row-1][0], costs[row-1][1]);
        }

        return min({costs[m-1][0], costs[m-1][1], costs[m-1][2]});
    }
};
