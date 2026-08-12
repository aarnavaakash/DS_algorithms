class Solution {
public:

    void updateFreq(int op, int val, vector<int>& freqBits) {
        int i = 0;
        while(val > 0) {
            if((val & 1)) {
                freqBits[i] += op;
            }

            val /= 2;
            i++;
        }
    }

    int minimumDifference(vector<int>& nums, int k) {
        vector<int> freqBits(32, 0);

        int n = nums.size();

        int i = 0;
        int j = 0;
        int windowAnd = nums[0];
        int result = INT_MAX;

        while(j < n) {
            windowAnd = windowAnd & nums[j];
            updateFreq(1, nums[j], freqBits);

            result = min(result, abs(k - windowAnd));

            if(windowAnd > k) {
                j++;
            } else if (windowAnd == k) {
                return 0;
            } else {
                while(i <= j && windowAnd < k) {
                    updateFreq(-1, nums[i], freqBits);
                    i++;
                    windowAnd = 0;
                    for(int b = 0; b < 32; b++){
                        if( (j-i+1) == freqBits[b]) {
                            windowAnd = windowAnd | (1<<b);
                        }
                    }
                    result = min(result, abs(k-windowAnd));
                }
                j++;
            }
        }

        return result;
    }
};
