class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> ranges;
        for (int num : nums) {
            ranges.push_back({num - k, num + k});
        }

        sort(ranges.begin(), ranges.end());

        int maxBeauty = 0;
        deque<int> deq;

        for (const auto& range : ranges) {
            while (!deq.empty() && deq.front() < range.first) {
                deq.pop_front();
            }

            deq.push_back(range.second);

            maxBeauty = max(maxBeauty, (int)deq.size());
        }

        return maxBeauty;
    }
};

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int maxBeauty = 0;

        for (int i = 0; i < nums.size(); i++) {
            auto upperBound = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k);

            maxBeauty = max(maxBeauty, int(upperBound - nums.begin()) - i);
        }

        return maxBeauty;
    }
};

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 0;
        int maxBeauty = 0;

        while (i < n) {

            while (j < n && nums[j] - nums[i] <= 2 * k) {
                j++;
            }

            maxBeauty = max(maxBeauty, j - i);

            i++;
        }

        return maxBeauty;
    }
};
