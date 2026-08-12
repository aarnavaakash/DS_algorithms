class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));

        if(nums.size() != maxEl+1)
            return false;

        vector<int> count(maxEl+1, 0);

        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;

            if(nums[i] != maxEl && count[nums[i]] > 1)
                return false;
            else if(nums[i] == maxEl && count[nums[i]] > 2)
                return false;
        }

        return true;
    }
};

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i = 0; i <= n-2; i++) {
            if(nums[i] != i+1)
                return false;
        }

        return nums[n-1] == n-1;
    }
};

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        int maxEl = n-1;

        int maxElCount = 0;

        for(int num : nums) {
            int val = abs(num);

            if(val > maxEl) {
                return false;
            } else if(val == maxEl) {
                maxElCount++;
            }

            if(nums[val] < 0) {
                if(val != maxEl) {
                    return false;
                } else if(maxElCount > 2) {
                    return false;
                }
            } else {
                nums[val] *= -1;
            }
        }

        return true;
    }
};
