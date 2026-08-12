class Solution {
public:
    int getClosestIndex(vector<int>& nums, int& targetIndex) {
        int pos = lower_bound(begin(nums), end(nums), targetIndex) - nums.begin();

        if(pos == 0)
            return nums[0];

        if(pos ==  nums.size()) {
            return nums[nums.size()-1];
        }

        if(nums[pos] - targetIndex < targetIndex - nums[pos-1])
            return nums[pos];

        return nums[pos-1];
    }

    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<int> result;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++) {
            mp[colors[i]].push_back(i);
        }

        for(vector<int> &query : queries) {
            int targetIndex = query[0];
            int targetColor = query[1];
            if(mp.find(targetColor) == end(mp)) {
                result.push_back(-1);
                continue;
            }

            int closeIdx = getClosestIndex(mp[targetColor], targetIndex);

            result.push_back(abs(targetIndex - closeIdx));
        }

        return result;
    }
};

int main() {
    vector<int> colors{1, 1, 2, 1, 3, 2, 2, 3, 3};
    vector<vector<int>> queries = {{1,3},{2,2},{6,1}};

    Solution obj;
    vector<int> result = obj.shortestDistanceColor(colors, queries);
    for(int &x : result)
        cout << x << " ";

return 0;
}
