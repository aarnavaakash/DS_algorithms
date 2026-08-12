class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> prev;

        for(int &num : nums)
            mp[num]++;

        for(int &num : nums) {
            if(mp[num] <= 0) continue;

            if(prev[num] > 0) {
                prev[num]--;
                prev[num+1]++;
                mp[num]--;
            } else if(mp[num] > 0 && mp[num+1] > 0 && mp[num+2] > 0) {
                mp[num]--;
                mp[num+1]--;
                mp[num+2]--;
                prev[num+3]++;
            } else {
                return false;
            }
        }

        return true;
    }
};
