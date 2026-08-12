class Solution {
public:

    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        for(int x = 0; x <=n; x++) {

            int i = lower_bound(begin(nums), end(nums), x) - begin(nums);

            if(n-i == x) {
                return x;
            }
        }

        return -1;
    }
};

class Solution {
public:

    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        int l = 0, r = n;
        while(l <= r) {
            int mid_x = l + (r-l)/2;

            int i = lower_bound(begin(nums), end(nums), mid_x) - begin(nums);

            if(n-i == mid_x) {
                return mid_x;
            } else if(n-i > mid_x) {
                l = mid_x+1;
            } else {
                r = mid_x-1;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n+1);

        for(int i = 0; i < n; i++) {
            freq[min(n, nums[i])]++;
        }

        int c_sum = 0;
        for(int i = n; i >= 0; i--) {
            c_sum += freq[i];
            if(i == c_sum) {
                return i;
            }
        }

        return -1;
    }
};
