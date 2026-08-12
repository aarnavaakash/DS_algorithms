class Solution {
public:
    int n;
    int minSum = INT_MAX;
    vector<int> result;

    void solve(vector<int>& nums, vector<bool>& visited, vector<int>& temp, int sum) {
        if (minSum <= sum)
            return;

        if (temp.size() == n) {
            sum += abs(temp.back() - nums[temp[0]]);
            if (sum < minSum) {
                minSum = sum;
                result = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.push_back(i);
                solve(nums, visited, temp, sum + abs(temp[temp.size() - 2] - nums[temp[temp.size() - 1]]));
                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n, false);
        vector<int> temp = {0};
        visited[0] = true;

        solve(nums, visited, temp, 0);
        return result;
    }
};
