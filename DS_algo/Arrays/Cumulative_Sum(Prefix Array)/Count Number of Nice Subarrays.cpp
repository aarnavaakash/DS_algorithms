class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n       = nums.size();
        int count   = 0;
        int currSum = 0;
        mp[currSum] = 1;

        for(int i = 0; i < n; i++) {
            currSum += (nums[i]%2);

            if(mp.count(currSum - k)) {
                count += mp[currSum-k];
            }

            mp[currSum]++;
        }

        return count;

    }
};

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int oddCount = 0;
        int count    = 0;
        int result   = 0;

        int i = 0;
        int j = 0;

        while(j < n) {

            if(nums[j] % 2 != 0) {
                oddCount++;
                count    = 0;
            }

            while(oddCount == k) {
                count++;

                if(i < n && nums[i] % 2 == 1) {
                    oddCount--;
                }
                i++;
            }

            result += count;
            j++;
        }

        return result;
    }
};
