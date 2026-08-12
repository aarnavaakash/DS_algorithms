class Solution {
public:
    int n;
    int solve(vector<int>& nums, int i, int k, vector<vector<int>>& t) {
        if(k == 0) {
            return 0;
        }

        if(i >= n) {
            return INT_MAX;
        }

        if(t[i][k] != -1) {
            return t[i][k];
        }

        int take = max(nums[i], solve(nums, i+2, k-1, t));

        int not_take = solve(nums, i+1, k, t);

        return t[i][k] = min(take, not_take);
    }
    int minCapability(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<int>> t(n+1, vector<int>(k+1, -1));
        return solve(nums, 0, k, t);
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int k) {
        int house = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mid) {
                house++;
                i++;
            }
        }

        return house >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int l = *min_element(begin(nums), end(nums));
        int r = *max_element(begin(nums), end(nums));

        int result = r;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(isPossible(nums, mid, k) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};
