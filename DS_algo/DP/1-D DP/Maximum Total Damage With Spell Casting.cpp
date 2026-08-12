class Solution {
public:
    typedef long long ll;
    int n;
    unordered_map<ll,ll> mp;
    vector<ll> t;

    long long solve(int i, const vector<ll>& nums) {
        if (i >= n)
            return 0;

        if (t[i] != -1)
            return t[i];

        ll skip = solve(i + 1, nums);

        int j = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
        ll take = nums[i] * mp[nums[i]] + solve(j, nums);

        return t[i] = max(skip, take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        for (int x : power)
            mp[x]++;

        vector<ll> nums(mp.size());

        for (auto &p : mp)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));
        n = nums.size();
        t.assign(n, -1);

        return solve(0, nums);
    }
};

class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<ll, ll> mp;

        for (int &x : power)
            mp[x]++;

        vector<ll> nums(mp.size());
        for (auto &p : mp)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<ll> t(n, 0);

        long long result = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {

            ll skip = (i + 1 < n) ? t[i + 1] : 0;

            int j   = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
            ll take = nums[i] * mp[nums[i]] + ((j < n) ? t[j] : 0);

            t[i]   = max(skip, take);
            result = max(result, t[i]);
        }

        return result;
    }
};
