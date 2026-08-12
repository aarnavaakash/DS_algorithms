class Solution {
public:
    vector<vector<int>> t;
    int solve(int i, vector<int>& rewardValues, int x) {
        if(i >= rewardValues.size())
            return 0;

        if(t[i][x] != -1)
            return t[i][x];

        int take = 0;
        if(x < rewardValues[i]) {
            take = rewardValues[i] + solve(i+1, rewardValues, x+rewardValues[i]);
        }
        int skip = solve(i+1, rewardValues, x);

        return t[i][x] = max(take, skip);
    }

    int maxTotalReward(vector<int>& rewardValues)  {
        int n = rewardValues.size();

        sort(rewardValues.begin(),rewardValues.end());

        t.resize(2001,vector<int>(4000, -1));

        return solve(0, rewardValues, 0);
    }
};
