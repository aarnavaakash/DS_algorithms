class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_A = accumulate(begin(A), end(A), 0);
        int sum_B = accumulate(begin(B), end(B), 0);

        unordered_set<int> st(begin(B), end(B));
        int target = (sum_B - sum_A)/2;
        for(int &x : A) {
            if(st.count(target+x))
                return {x, target+x};
        }
        return {};
    }
};
