class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        for(int j = 1; j < n; j++) {
            int max_val = 0;
            for(int i = j-1; i >= 0; i--) {
                max_val = max(max_val, values[i]+i);
            }

            result = max(result, max_val + values[j]-j);
        }

        return result;
    }
};

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> vec(n, 0);

        vec[0] = values[0] + 0;

        for(int i = 1; i < n; i++) {
            vec[i] = max(values[i]+i, vec[i-1]);
        }

        int result = 0;

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = vec[j-1];

            result = max(result, x+y);
        }

        return result;
    }
};

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        int max_till_now = values[0]+0;

        for(int j = 1; j < n; j++) {
            int x = values[j]-j;
            int y = max_till_now;

            result = max(result, x+y);

            max_till_now = max(max_till_now, values[j]+j);
        }

        return result;
    }
};
