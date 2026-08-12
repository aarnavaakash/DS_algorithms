class Solution {
public:
    vector<vector<int>> result;
    void generate(vector<int>& nums, vector<int>& temp, int idx, int k, int target) {
        if(target == 0 && temp.size() == k) {
            result.push_back(temp);
            return;
        }

        if(idx >= nums.size() || target < 0) {
            return;
        }

        for(int i = idx; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            generate(nums, temp, i+1, k, target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;

        generate(nums, temp, 0, k, n);

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> result;

    void generate(int num, vector<int>& temp, int k, int target) {
        if(target == 0 && temp.size() == k) {
            result.push_back(temp);
            return;
        }

        if(num >= 10 || target < 0) {
            return;
        }

        for(int i = num; i<10; i++) {
            temp.push_back(i);
            generate(i+1, temp, k, target-i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int num = 1;
        vector<int> temp;

        generate(num, temp, k, n);

        return result;
    }
};
