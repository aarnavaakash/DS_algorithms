class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int& num : nums) {
            st.insert(num);
        }

        int maxL = 0;
        for(int& num : nums) {
            int prevNum = num-1;
            if(st.find(prevNum) == st.end()) {

                int tempL     = 0;
                int currNum   = num;

                while(st.find(currNum) != st.end()) {
                    tempL++;
                    currNum++;
                }

                maxL = max(maxL, tempL);

            }
        }

        return maxL;
    }
};
