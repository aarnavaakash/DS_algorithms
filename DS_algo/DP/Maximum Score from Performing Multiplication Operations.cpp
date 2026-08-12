class Solution {
public:
    int n, m;
    unordered_map<string, int> mp;
    int solve(vector<int>& nums, int i, int j, vector<int>& multi, int k) {
        if(k >= m || i > j)
            return 0;

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(k);

        if(mp.find(key) != mp.end())
            mp[key];

        int choose_left  = nums[i]*multi[k];
        int choose_right = nums[j]*multi[k];

        return mp[key] = max(choose_left + solve(nums, i+1, j, multi, k+1),
                  choose_right + solve(nums, i, j-1, multi, k+1));
    }

    int maximumScore(vector<int>& nums, vector<int>& multi) {
        n = nums.size();
        m = multi.size();
        mp.clear();
        int i = 0;
        int j = n-1;
        int k = 0;
        return solve(nums, i, j, multi, k);
    }
};

class Solution {
public:
    int n, m;
    int t[1001][1001];
    int solve(vector<int>& nums, int i, vector<int>& multi, int k) {
        if(k >= m)
            return 0;

        int j = (n-1) - (k-i);

        if(t[i][k] != INT_MIN)
            return t[i][k];

        int choose_left  = nums[i]*multi[k];
        int choose_right = nums[j]*multi[k];

        return t[i][k] = max(choose_left + solve(nums, i+1, multi, k+1),
                  choose_right + solve(nums, i, multi, k+1));
    }

    int maximumScore(vector<int>& nums, vector<int>& multi) {
        n = nums.size();
        m = multi.size();

        for(int i = 0; i<1001; i++) {
            for(int j = 0; j<1001; j++) {
                t[i][j] = INT_MIN;
            }
        }

        int i = 0;
        int k = 0;
        return solve(nums, i, multi, k);
    }
};
