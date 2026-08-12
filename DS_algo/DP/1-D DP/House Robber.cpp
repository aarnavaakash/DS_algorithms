class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int& n) {
        if(i >= n)
            return 0;

        if(t[i] != -1)
            return t[i];

        int take = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i]=max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> t(n+1);

        t[0] = 0;
        t[1] = nums[0];

        for(int i = 2; i<=n; i++) {

            int skip  = t[i-1];
            int steal = nums[i-1] + t[i-2];

            t[i] = max(skip, steal);

        }

        return t[n];

    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prevPrev = 0;
        int prev     = nums[0];

        for(int i = 2; i<=n; i++) {
            int skip = prev;

            int take = nums[i-1] + prevPrev;

            int temp = max(skip, take);

            prevPrev = prev;
            prev     = temp;
        }

        return prev;
    }
};
