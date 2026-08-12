class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n)
            return nums;

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = make_pair(i, nums[i]);
        }

        auto lambda = [](auto &p1, auto& p2) {
            return p1.second > p2.second;
        };

        sort(begin(vec), end(vec), lambda);

        sort(begin(vec), begin(vec)+k);

        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(vec[i].second);
        }

        return result;
    }
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if (k == nums.size())
            return nums;

        vector<int> temp(nums);

        nth_element(begin(temp), begin(temp) + k - 1, end(temp), greater<int>());

        int threshold = temp[k - 1];

        int countThreshold = count(temp.begin(), temp.begin() + k, threshold);

        vector<int> result;
        for (int num : nums) {
            if (num > threshold) {
                result.push_back(num);
            } else if (num == threshold && countThreshold > 0) {
                result.push_back(num);
                --countThreshold;
            }
            if (result.size() == k)
                break;
        }

        return result;
    }
};
