class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        long long result = 0;

        int curr = 0;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            curr = target[i];

            if(abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }

            prev = curr;
        }

        return result;
    }
};
