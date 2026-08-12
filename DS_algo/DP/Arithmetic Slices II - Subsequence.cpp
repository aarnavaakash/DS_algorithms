class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<long, int> mp[n];

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                auto diff = (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);

                int count_at_j = it==end(mp[j]) ? 0 : it->second;

                mp[i][diff] += count_at_j+1;
                result      += count_at_j;

            }
        }
        return result;
    }
};

class Solution {
private:
    int solve(vector<int>& nums, int start, int curr, int len, long diff, unordered_map<string, int>& dp) {
        if (curr == nums.size() - 1)
            return 0;

        string temp = to_string(curr) + "#" + to_string(len);
        if (dp.find(temp) != dp.end())
            return dp[temp];

        int res = 0;
        for (int i = curr + 1; i < nums.size(); i++) {
            long k = static_cast<long>(nums[i]) - static_cast<long>(nums[curr]);
            if (len == 1 || diff == k) {
                len += 1;
                if (len >= 3)
                    res++;
                res += solve(nums, start, i, len, k, dp);
                len -= 1;
            }
        }

        dp[temp] = res;
        return res;
    }

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        unordered_map<string, int> dp;

        for (int i = 0; i < nums.size(); i++) {
            dp.clear();
            res += solve(nums, i, i, 1, 0, dp);
        }

        return res;
    }
};
