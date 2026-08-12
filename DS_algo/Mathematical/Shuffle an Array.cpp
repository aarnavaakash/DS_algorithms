class Solution {
public:
    vector<int> nums;
    int n;
    Solution(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        srand(time(0));
    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        vector<int> result(nums);
        for(int i = 0; i<n; i++) {
            int idx = rand()%(n-i);

            swap(result[i], result[i+idx]);
        }
        return result;
    }

};
