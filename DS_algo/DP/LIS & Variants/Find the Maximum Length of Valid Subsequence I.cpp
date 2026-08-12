class Solution {
public:

    int LIS(vector<int>& nums, int i, int prev, int mod) {
        if(i >= nums.size()) {
            return 0;
        }

        int take = 0;
        int skip = 0;

        if(prev == -1 || (nums[prev] + nums[i])%2 == mod) {
            take = 1 + LIS(nums, i+1, i, mod);
        }

        skip = LIS(nums, i+1, prev, mod);

        return max(take, skip);
    }

    int maximumLength(vector<int>& nums) {
        int maxSubLength = 0;

        maxSubLength = max(maxSubLength, LIS(nums, 0, -1, 0));
        maxSubLength = max(maxSubLength, LIS(nums, 0, -1, 1));

        return maxSubLength;

    }
};

class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(2, vector<int>(n, 1));
        int maxSub = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int mod = (nums[j] + nums[i])%2;

                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = max(maxSub, dp[mod][i]);
            }
        }

        return maxSub;
    }
};
