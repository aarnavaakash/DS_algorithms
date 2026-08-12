class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i<n-1; i++) {
            int num = nums[i];

            for(int j = i+1; j<n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> mp;

        for(int &num : nums) {
            mp[num]++;
        }

        for(auto &it : mp) {

            int count = it.second;
            result += (count * (count-1))/2;

        }

        return result;
    }
};

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> mp;

        for(int &num : nums) {
            result += mp[num]++;
        }

        return result;
    }
};
