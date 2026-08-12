class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        return (nums[n-1] * nums[n-2]) - (nums[1] * nums[0]);
    }
};

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(int &num : nums) {
            if(num > largest) {
                secondLargest = largest;
                largest = num;
            } else {
                secondLargest = max(secondLargest, num);
            }

            if(num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = min(secondSmallest, num);
            }

        }

        return (largest * secondLargest) - (secondSmallest * smallest);

    }
};
