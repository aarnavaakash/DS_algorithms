class Solution {
public:
    int t[201][10001];
    bool isSubsetSum(int n, int sum, vector<int>& arr) {
        if(sum == 0)
            return true;

        if(n == 0)
            return false;

        if(t[n][sum] != -1) {
            return t[n][sum];
        }

        bool skip = isSubsetSum(n-1, sum, arr);

        bool take = false;
        if(arr[n-1] <= sum) {
            take = isSubsetSum(n-1, sum - arr[n-1], arr);
        }

        return t[n][sum] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();

        int SUM = accumulate(begin(nums), end(nums), 0);

        if(SUM % 2 != 0) {
            return false;
        }

        int S = SUM/2;

        return isSubsetSum(n, S, nums);
    }
};

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<vector<bool>> t(n+1, vector<bool>(sum + 1, false));

        for (int i = 0; i < n+1; i++)
            t[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool skip = t[i-1][j];

                bool take = false;
                if(arr[i-1] <= j) {
                    take = t[i-1][j - arr[i-1]];
                }

                t[i][j] = take || skip;
            }
        }

        return t[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int SUM = accumulate(begin(nums), end(nums), 0);

        if(SUM % 2 != 0) {
            return false;
        }

        int S = SUM/2;

        return isSubsetSum(nums, S);
    }
};
