class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        int n    = nums.size();
        int limit = (1 << n);

        for(int mask = 0; mask < limit; mask++) {
            vector<int> temp;

            for(int i = 0; i<n; i++) {
                if( (mask & (1 << i)) != 0 ) {
                    temp.push_back(nums[i]);
                }
            }

            result.push_back(temp);
        }

        return result;

    }
};
