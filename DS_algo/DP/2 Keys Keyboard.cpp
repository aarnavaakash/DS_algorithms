class Solution {
public:
    int t[1001][1001];
    int solve(int currCountA, int pasteCountA, int n) {
        if(currCountA == n) {
            return 0;
        }

        if(currCountA > n) {
            return 1000;
        }

        if(t[currCountA][pasteCountA] != -1) {
            return t[currCountA][pasteCountA];
        }

        int copyPaste = 1 + 1 + solve(currCountA + currCountA, currCountA, n);

        int paste     = 1 + solve(currCountA + pasteCountA, pasteCountA, n);

        return t[currCountA][pasteCountA] = min(copyPaste, paste);
    }

    int minSteps(int n) {
        if(n == 1)
            return 0;

        memset(t, -1, sizeof(t));

        return 1 + solve(1, 1, n);
    }
};

class Solution {
public:

    int minSteps(int n) {

        if(n == 1)
            return 0;

        if(n == 2)
            return 2;

        vector<int> t(n+1, 0);

        t[0] = 0;
        t[1] = 0;
        t[2] = 2;

        for(int i = 3; i<=n; i++) {

            int factor = i/2;
            while(factor >= 1) {
                if(i%factor == 0) {

                    int steps_to_reach_factor = t[factor];
                    int copy_that_first       = 1;
                    int paste_frequency       = (i/factor) - 1;

                    t[i] = t[factor] + copy_that_first + paste_frequency;
                    break;
                }
                factor--;
            }
        }

        return t[n];
    }
};

class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;

        int remaining = n;
        int buffer    = 0;
        int count_A   = 1;
        int steps     = 0;

        while(count_A < n) {
            remaining = n-count_A;
            if(remaining%count_A == 0) {
                buffer     = count_A;
                count_A   *= 2;
                steps     += 2;
            } else {
                count_A   += buffer;
                steps++;
            }
        }

        return steps;
    }
};
