class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;

        for (int &i : nums) {
            for (int &j : nums) {

                if (i == -j) {

                    result = max(result, abs(i));
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            if (-nums[i] == nums[j]) {
                return nums[j];
            }
            else if (-nums[i] < nums[j]) {
                j--;
            }
            else {
                i++;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> seen;

        int result = -1;

        for(int num : nums) {
            if (seen.count(-num)) {
                result = max(result, abs(num));
            }
            seen.insert(num);
        }

        return result;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;

        int arr[2001] = {0};

        for (int num : nums) {

            if (arr[-num + 1000] == 1)
                result = max(result, abs(num));

            arr[num + 1000] = 1;
        }

        return result;
    }
};
