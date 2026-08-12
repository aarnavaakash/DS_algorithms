class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();

        if(p == 0)
            return n;

        int counter[26] = {0};
        for(char &ch : tasks) {
            counter[ch-'A']++;
        }

        sort(begin(counter), end(counter));

        int chunks      = counter[25]-1;
        int idolSpots   = chunks*p;

        for(int i = 24; i>=0 ; i--) {
            idolSpots -= min(chunks, counter[i]);
        }

        if(idolSpots > 0)
            return n + idolSpots;

        return n;
    }
};
