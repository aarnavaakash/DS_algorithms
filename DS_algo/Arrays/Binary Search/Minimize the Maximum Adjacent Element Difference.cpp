class Solution {
public:
    bool check(vector<int>& nums, int x, int y, int d) {
        int count = 0;
        int prev  = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == -1) {

                if(prev != 0 && min(abs(prev-x), abs(prev-y)) > d) {
                    return false;
                }
                count++;
            } else {
                if(count > 0) {
                    int absDiffResult;
                    if(prev != 0) {

                        absDiffResult = min(
                            max(abs(prev-x), abs(nums[i]-x)),
                            max(abs(prev-y), abs(nums[i]-y))
                        );
                    } else {

                        absDiffResult = min(abs(nums[i] - x), abs(nums[i] - y));
                    }

                    bool canMixXAndY = (count >= 2 && abs(x-y) <= d);

                    if(absDiffResult > d && !canMixXAndY)
                        return false;
                }

                prev  = nums[i];
                count = 0;
            }
        }

        return true;
    }

    int minDifference(vector<int>& nums) {
        int n = nums.size();

        int min_val    = INT_MAX;
        int max_val    = 0;
        int maxAdsDiff = 0;

        for(int i = 0; i < n-1; i++) {
            if(nums[i] != -1 && nums[i+1] != -1) {
                maxAdsDiff = max(maxAdsDiff, abs(nums[i] - nums[i+1]));
            } else if(!(nums[i] == -1 && nums[i+1] == -1)) {
                int val = max(nums[i], nums[i+1]);
                min_val = min(min_val, val);
                max_val = max(max_val, val);
            }
        }

        int l = maxAdsDiff;
        int r = max_val - min_val;

        int result = maxAdsDiff;
        while(l <= r) {
            int d = l + (r-l)/2;
            int x = min_val + d;
            int y = max_val - d;
            if(check(nums, x, y, d)) {
                result = d;
                r = d-1;
            } else {
                l = d+1;
            }
        }

        return result;
    }
};
