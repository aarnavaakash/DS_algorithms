class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length, 0);

        for (const auto& update : updates) {
            int start = update[0];
            int end   = update[1];
            int x     = update[2];

            diff[start] += x;
            if (end + 1 < length) {
                diff[end + 1] -= x;
            }
        }

        vector<int> result(length, 0);

        int cumSum = 0;
        for (int i = 0; i < length; ++i) {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        return result;
    }
};
