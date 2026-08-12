class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();

        vector<int> prev(W+1, 0), curr(W+1, 0);

        for(int i = 1; i < n+1; i++) {

            for(int j = 1; j < W+1; j++) {

                int take = 0;
                int skip = 0;

                if(wt[i-1] <= j) {
                    take = val[i-1] + prev[j - wt[i-1]];
                }

                skip = prev[j];

                curr[j] = max(take, skip);
            }

            prev = curr;
        }

        return prev[W];
    }
};
