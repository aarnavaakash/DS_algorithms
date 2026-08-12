class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums, int i, int x) {
        if(x == 0) {
            return true;
        }

        if(i >= nums.size()) {
            return false;
        }

        if(t[i][x] != -1) {
            return t[i][x];
        }

        bool take = false;
        if(nums[i] <= x) {
            take = solve(nums, i+1, x - nums[i]);
        }

        bool not_take = solve(nums, i+1, x);

        return t[i][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int S = accumulate(begin(nums), end(nums), 0);

        if(S%2 != 0) {
            return false;
        }
        memset(t, -1, sizeof(t));

        int x = S/2;

        return solve(nums, 0, x);

    }
};

class Solution {
public:
    bool subsetSum(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<bool>> t(n+1, vector<bool>(S+1, false));

        for(int col = 0; col<S+1; col++) {
            t[0][col] = false;
        }

        for(int row = 0; row<n+1; row++) {
            t[row][0] = true;
        }

        for(int i = 1; i<n+1; i++) {
            for(int j = 1; j<S+1; j++) {
                if(nums[i-1] <= j) {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][S];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums){
            sum += x;
        }

        if(sum%2 != 0)
            return false;

        sum = sum/2;

        return subsetSum(nums, sum);
    }
};
