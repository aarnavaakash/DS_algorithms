class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int totalNumberOfTuples = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {

                        if (i != k && i != l && j != k && j != l) {
                            int product1 = nums[i] * nums[j];
                            int product2 = nums[k] * nums[l];

                            if (product1 == product2) {
                                totalNumberOfTuples++;
                            }
                        }
                    }
                }
            }
        }

        return (totalNumberOfTuples / 2) * 8;

    }
};

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int totalNumberOfTuples = 0;
        int n = nums.size();
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i++) {
            for (int j = n-1; j > i; j--) {

                for(int k = i+1; k < j; k++) {
                    for(int l = j-1; l > k; l--) {

                        int p1 = nums[i] * nums[j];
                        int p2 = nums[k] * nums[l];

                        if(p1 == p2) {
                            totalNumberOfTuples++;
                        }

                    }
                }

            }
        }

        return totalNumberOfTuples * 8;
    }
};

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int totalNumberOfTuples = 0;
        int n = nums.size();

        int result = 0;
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {

                int product = nums[i] * nums[j];
                unordered_set<int> st;

                for (int k = i+1; k < j; k++) {

                    if(product % nums[k] == 0) {
                        int lValue = product/nums[k];

                        if(st.count(lValue)) {
                            totalNumberOfTuples++;
                        }

                        st.insert(nums[k]);
                    }
                }
            }
        }

        return totalNumberOfTuples * 8;
    }
};

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuples = 0;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int p = nums[i] * nums[j];
                mp[p]++;
            }
        }

        for(auto &it : mp) {
            int prod = it.first;
            int freq = it.second;

            tuples += (freq * (freq-1))/2;
        }

        return tuples * 8;
    }
};
