class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> cumSum(n);
        cumSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + nums[i];
        }

        int split = 0;

        for (int i = 0; i < n - 1; i++) {

            long long leftSum = cumSum[i];

            long long rightSum = cumSum[n - 1] - cumSum[i];

            if (leftSum >= rightSum) {
                split++;
            }
        }

        return split;
    }
};

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        for(int &num : nums) {
            sum += num;
        }

        long long leftSum  = 0;
        long long rightSum = 0;
        int split = 0;

        for(int i = 0; i < n-1; i++) {
            leftSum += nums[i];

            rightSum = sum - leftSum;

            if(leftSum >= rightSum) {
                split++;
            }
        }
        return split;
    }
};
