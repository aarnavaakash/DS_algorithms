class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();

        vector<vector<int>> t(n+1, vector<int>(W+1, 0));

        for(int j = 0; j < W+1; j++) {
            t[0][j] = 0;
        }

        for(int i = 0; i < n+1; i++) {
            t[i][0] = 0;
        }

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < W+1; j++) {

                int take = 0;
                int skip = 0;

                if(wt[i-1] <= j) {
                    take = val[i-1] + t[i-1][j - wt[i-1]];
                }

                skip    = t[i-1][j];

                t[i][j] = max(take, skip);

            }
        }

        return t[n][W];
    }
};
