class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        for(int i = 0; i < n; i++) {
            int increasing = 1;
            int j = i+1;
            while(j < n && nums[j] > nums[j-1]) {
                increasing++;
                j++;
            }

            int decreasing = 1;
            j = i+1;

            while(j < n && nums[j] < nums[j-1]) {
                decreasing++;
                j++;
            }

            result = max({result, increasing, decreasing});
        }

        return result;
    }
};

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 1;
        int increasing = 1;
        int decreasing = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                increasing++;
                decreasing = 1;
                result = max(result, increasing);
            } else if(nums[i] < nums[i-1]) {
                decreasing++;
                increasing = 1;
                result = max(result, decreasing);
            } else {
                increasing = 1;
                decreasing = 1;
            }
        }

        return result;
    }
};
