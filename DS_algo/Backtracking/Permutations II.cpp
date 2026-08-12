class Solution {
public:
    int n;
    vector<vector<int>> result;
    void backtrack(vector<int>& temp, unordered_map<int, int>& mp) {

        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }

        for (auto& [num, count] : mp) {

            if (count == 0)
                continue;

            temp.push_back(num);
            mp[num]--;

            backtrack(temp, mp);

            temp.pop_back();
            mp[num]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;

        for (int& num : nums) {
            mp[num]++;
        }

        vector<int> temp;
        backtrack(temp, mp);

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int idx, vector<int>& nums) {
        if(idx == n) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> uniqueSet;
        for(int i = idx; i < n; i++) {

            if(uniqueSet.count(nums[i]) > 0) {
                continue;
            }

            uniqueSet.insert(nums[i]);

            swap(nums[i], nums[idx]);

            solve(idx+1, nums);

            swap(nums[i], nums[idx]);

        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        solve(0, nums);

        return result;
    }
};
