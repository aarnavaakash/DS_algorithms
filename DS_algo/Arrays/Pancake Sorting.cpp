class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int> result;
        while(n!=1) {
            if(A[n-1] == n) {
                n--
                continue;
            }

            int index = find(A.begin(), A.end(), n) - A.begin();

            if(index != 0) {
                reverse(A.begin(), A.begin()+index+1);
                result.push_back(index+1);
            }

            reverse(A.begin(), A.begin()+n);
            result.push_back(n);
            n--;
        }
        return result;
    }
};
