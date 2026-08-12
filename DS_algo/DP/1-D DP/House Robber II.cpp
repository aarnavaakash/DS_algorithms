class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n) {
        if(i > n)
            return 0;

        if(t[i] != -1)
            return t[i];

        int take = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i]=max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);

        memset(t, -1, sizeof(t));

        int take_0th_index_house = solve(nums, 0, n-2);

        memset(t, -1, sizeof(t));

        int take_1st_index_house = solve(nums, 1, n-1);

        return max(take_0th_index_house, take_1st_index_house);

    }
};

class Solution {
public:
    int n;

    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1)
            return nums[0];

        vector<int> t(n+1, 0);

        int result1 = 0;
        int result2 = 0;

        t[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result1 = t[n-1];

        t.clear();

        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result2 = t[n];

        return max(result1, result2);

    }
};

class Solution {
public:

    int solve(vector<int>& nums, int l, int r) {

        int prevPrev = 0, prev = 0;

        for(int i = l; i<=r; i++) {
            int skip = prev;
            int take = nums[i] + prevPrev;

            int temp = max(skip, take);

            prevPrev = prev;
            prev     = temp;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);

        int take_first_house = solve(nums, 0, n-2);

        int skip_first_house = solve(nums, 1, n-1);

        return max(take_first_house, skip_first_house);
    }
};
