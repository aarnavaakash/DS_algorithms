class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;

        int sum = 0;

        int maxNeg = INT_MIN;

        for(int &num : nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            } else if(!st.count(num)) {
                sum += num;
                st.insert(num);
            }
        }

        return sum == 0 ? maxNeg : sum;
    }
};

class Solution {
public:
    int maxSum(vector<int>& nums) {

        vector<int> st(101, -1);

        int sum = 0;

        int maxNeg = INT_MIN;

        for(int &num : nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            } else if(st[num] == -1) {
                sum += num;

                st[num] = 1;
            }
        }

        return sum == 0 ? maxNeg : sum;
    }
};
