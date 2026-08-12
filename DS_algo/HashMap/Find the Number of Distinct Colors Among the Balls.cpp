class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);

        unordered_map<int, int> colormp;

        vector<int> ballArr(limit+1, -1);

        for(int i = 0; i < n; i++) {
            int ball  = queries[i][0];
            int color = queries[i][1];

            if(ballArr[ball] != -1) {
                int prevColor = ballArr[ball];
                colormp[prevColor]--;

                if(colormp[prevColor] == 0) {
                    colormp.erase(prevColor);
                }
            }

            ballArr[ball] = color;
            colormp[color]++;

            result[i] = colormp.size();
        }

        return result;

    }
};

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);

        unordered_map<int, int> colormp;
        unordered_map<int, int> ballmp;

        for(int i = 0; i < n; i++) {
            int ball  = queries[i][0];
            int color = queries[i][1];

            if(ballmp.count(ball)) {
                int prevColor = ballmp[ball];
                colormp[prevColor]--;

                if(colormp[prevColor] == 0) {
                    colormp.erase(prevColor);
                }
            }

            ballmp[ball] = color;
            colormp[color]++;

            result[i] = colormp.size();
        }

        return result;

    }
};
