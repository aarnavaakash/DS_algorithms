class Solution {
public:
    int n;
    int visited[16];

    bool possible(vector<int>& matchsticks, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1)
            return true;
        if(currSum == subsetSum) {
            return possible(matchsticks, n-1, 0, subsetSum, k-1);
        }

        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || currSum + matchsticks[i] > subsetSum)
                continue;

            visited[i] = 1;
            currSum   += matchsticks[i];

            if(possible(matchsticks, i+1, currSum, subsetSum, k))
                return true;

            visited[i] = 0;
            currSum   -= matchsticks[i];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(begin(matchsticks), end(matchsticks), 0);
        int k   = 4;

        if(sum%4 != 0)
            return false;

        memset(visited, 0, sizeof(visited));
        sort(begin(matchsticks), end(matchsticks));

        n                   = matchsticks.size();
        int subsetSum       = sum/4;
        int numsIndex       = n-1;
        int currSum         = matchsticks[numsIndex];
        visited[numsIndex]  = 1;

        return possible(matchsticks, numsIndex, currSum, subsetSum, k);
    }
};
