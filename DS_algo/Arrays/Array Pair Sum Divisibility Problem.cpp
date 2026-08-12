class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int count = 0;
        if(n%2) return false;

        for(int i = 0; i<n; i++) {
            mp[nums[i]%k]++;
        }

        for(int i = 0; i<n; i++) {
            int remain = nums[i]%k;

            if(remain == 0) {
                if(mp[remain]%2) return false;
            } else if(2*remain == k) {
                if(mp[remain]%2) return false;
            } else {

                int findremain = k-remain;

                if(mp[remain] != mp[findremain])
                    return false;
            }
        }

        return true;
    }
};
