class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;

        for(int i = 0; i<nums.size(); i++) {

            if(nums[i]%2 == 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return nums;
    }
};

class Solution {
public:

    static bool comparator(int a, int b) {
        return a%2 < b%2;
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums), end(nums), comparator);

        return nums;
    }
};
