class Solution {
public:
    int funct(vector<int>& prefSum, int L, int M) {
        int n = prefSum.size();
        int maxLeftSubSum = 0;
        int result = 0;

        for(int mEnd = L + M - 1; mEnd < n; mEnd++) {
            int lEnd = mEnd - M;
            int lStartPrev = lEnd - L;

            int mBlockSum = prefSum[mEnd] - prefSum[lEnd];
            int lBlockSum = prefSum[lEnd] - (lStartPrev < 0 ? 0 : prefSum[lStartPrev]);

            maxLeftSubSum = max(maxLeftSubSum, lBlockSum);

            result = max(result, maxLeftSubSum + mBlockSum);
        }

        return result;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();

        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i];
        }

        return max(funct(prefSum, L, M), funct(prefSum, M, L));

    }
};

class Solution {
public:

    int funct(vector<int>& nums, int L, int M) {
        int n = nums.size();

        int lBlockSum = 0;
        int mBlockSum = 0;

        for(int i = 0; i <= L+M-1; i++) {
            if(i < L) {
                lBlockSum += nums[i];
            } else {
                mBlockSum += nums[i];
            }
        }

        int maxLeftSubSum = lBlockSum;
        int result = maxLeftSubSum + mBlockSum;

        for(int mEnd = L + M; mEnd < n; mEnd++) {
            lBlockSum += nums[mEnd-M] - nums[mEnd - M - L];
            mBlockSum += nums[mEnd] - nums[mEnd - M];

            maxLeftSubSum = max(maxLeftSubSum, lBlockSum);

            result = max(result, maxLeftSubSum + mBlockSum);
        }

        return result;

    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();

        return max(funct(nums, L, M), funct(nums, M, L));
    }
};
