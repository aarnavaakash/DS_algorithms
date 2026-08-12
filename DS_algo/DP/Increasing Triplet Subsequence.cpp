class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);

        int max_val = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i])
                    t[i] = max(t[i], t[j]+1);
            }
            max_val = max(max_val, t[i]);
            if(max_val >= 3)
                break;
        }

        return max_val>=3?true:false;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        int num1 = INT_MAX;
        int num2 = INT_MAX;

        for(int i = 0; i<n; i++) {

            int num3 = nums[i];

            if(num3 <= num1) {
                num1 = num3;
            } else if(num3 <= num2) {
                num2 = num3;
            } else {
                return true;
            }
        }

        return false;

    }
};
