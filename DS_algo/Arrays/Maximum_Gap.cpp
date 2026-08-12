Simply sort and find the maximum gap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;

        auto mm  = minmax_element(begin(nums), end(nums));
        int minN = *mm.first;
        int maxN = *mm.second;

        int bucketSize = ceil((float)(maxN-minN)/(float)(n-1));

        vector<int> minBucket(n-1, INT_MAX);
        vector<int> maxBucket(n-1, INT_MIN);

        for(int &x : nums) {
            if(x == minN || x == maxN)
                continue;

            int bucketIdx = (x-minN)/bucketSize;
            minBucket[bucketIdx] = min(minBucket[bucketIdx], x);
            maxBucket[bucketIdx] = max(maxBucket[bucketIdx], x);
        }

        int maxGap = 0;
        int prev = minN;
        for(int i = 0; i<n-1; i++) {
            if(minBucket[i] == INT_MAX || maxBucket[i] == INT_MIN)
                continue;

            int currBucketMin = minBucket[i];

            maxGap = max(maxGap, currBucketMin-prev);
            prev = maxBucket[i];
        }

        maxGap = max(maxGap, maxN-prev);

        return maxGap;

    }
};
