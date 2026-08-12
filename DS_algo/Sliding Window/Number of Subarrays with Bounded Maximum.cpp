class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        int i = 0, j = 0;
        int count = 0;
        int prevC = 0;
        int n = nums.size();
        while(j < n) {
            if(nums[j] >= L && nums[j] <= R) {
                prevC   = j-i+1;
                count += prevC;
            } else if(nums[j] < L) {
                count += prevC;
            } else {
                i     = j+1;
                prevC = 0;
            }
            j++;
        }

        return count;
    }
};
