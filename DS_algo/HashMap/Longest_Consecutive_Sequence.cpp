class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> mp;

        for(int &x : nums)
            mp[x] = true;

        for(int &x : nums) {

            if(mp.find(x-1) != mp.end()) {
                mp[x] = false;
            }
        }

        int maxL = 0;
        for(auto it : mp) {
            int x = it.first;
            if(it.second == true) {
                int tempL = 1;

                while(mp.find(x+tempL) != mp.end()) {
                     tempL++;
                }

                maxL = max(maxL, tempL);
            }
        }

        return maxL;

    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));

        int maxL = 0;

        for(const int &x : st) {

            if(st.find(x-1) != st.end()) {
                continue;
            }

            int tempL = 1;
            while(st.find(x+tempL) != st.end()) {
                tempL++;
            }

            maxL = max(maxL, tempL);
        }

        return maxL;

    }
};
