class Solution {
public:

    int kadanesMax(vector<int>& nums, int n) {
        int sum     = nums[0];
        int maxSum  = nums[0];

        for(int i = 1; i<n; i++) {
            sum     = max(sum + nums[i], nums[i]);
            maxSum  = max(maxSum, sum);
        }

        return maxSum;
    }

    int kadanesMin(vector<int>& nums, int n) {
        int sum     = nums[0];
        int minSum  = nums[0];

        for(int i = 1; i<n; i++) {
            sum     = min(sum + nums[i], nums[i]);
            minSum  = min(minSum, sum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);

        int minSum = kadanesMin(nums, n);

        int maxSum = kadanesMax(nums, n);

        int circSum = SUM - minSum;

        if(maxSum > 0) {
            return max(maxSum, circSum);
        }

        return maxSum;
    }
};

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n   = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);

        int k_sum_min = nums[0];
        int min_sum   = nums[0];

        int k_sum_max = nums[0];
        int max_sum   = nums[0];

        for(int i = 1; i<nums.size(); i++) {

            min_sum   = min(nums[i]+min_sum, nums[i]);
            k_sum_min = min(k_sum_min, min_sum);

            max_sum = max(nums[i]+max_sum, nums[i]);
            k_sum_max = max(k_sum_max, max_sum);

        }

        int circular_sum = SUM - k_sum_min;

        if(k_sum_max > 0) {
            return max(k_sum_max, circular_sum);
        }

        return k_sum_max;

    }
};
