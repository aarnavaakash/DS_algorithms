class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int modify = false;
        int n      = nums.size();

        for(int i = 0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                if(modify)
                    return false;

                modify = true;
                if(i > 0 && nums[i-1] > nums[i+1])
                    nums[i+1] = nums[i];
                else
                    nums[i] = nums[i+1];
            }
        }

        return true;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool modify = false;
        int min = INT_MIN;
        for(int i = 0; i<n-1; i++) {
            if(nums[i] <= nums[i+1])
                min = nums[i];
            else {
                if(nums[i+1] < min) {

                    nums[i+1] = nums[i];
                }
                if(modify)
                    return false;
                modify = true;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int modify = false;
        int n      = nums.size();

        for(int i = 1; i<n; i++) {
            if(nums[i] < nums[i-1]) {

                if(i == 1 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];

                if(modify)
                    return false;
                modify = true;
            }
        }

        return true;
    }
};
