class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;

        for (int start = 0; start < n; ++start) {
            int currentMin = nums[start];
            int currentMax = nums[start];

            for (int end = start; end < n; ++end) {
                currentMin = min(currentMin, nums[end]);
                currentMax = max(currentMax, nums[end]);

                if (currentMin == minK && currentMax == maxK) {
                    count++;
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int minPosition = -1;
        int maxPosition = -1;
        int leftBound   = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < minK || nums[i] > maxK)
                leftBound = i;

            if(nums[i] == minK)
                minPosition = i;
            if(nums[i] == maxK)
                maxPosition = i;

            int count = min(maxPosition, minPosition) - leftBound;

            ans += (count <= 0) ? 0 : count;

        }

        return ans;
    }
};
