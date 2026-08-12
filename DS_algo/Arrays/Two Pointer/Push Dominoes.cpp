class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();

        vector<int> rightClosestL(n);
        vector<int> leftClosestR(n);

        for(int i = n-1; i>=0; i--) {
            if(dominoes[i] == 'L')
                rightClosestL[i] = i;
            else if(dominoes[i] == '.')
                rightClosestL[i] = i < n-1 ? rightClosestL[i+1] : -1;
            else
                rightClosestL[i] = -1;
        }

        for(int i = 0; i<n; i++) {
            if(dominoes[i] == 'R')
                leftClosestR[i] = i;
            else if(dominoes[i] == '.')
                leftClosestR[i] = i > 0 ? leftClosestR[i-1] : -1;
            else
                leftClosestR[i] = -1;
        }

        string result(n, ' ');

        for(int i = 0; i<n; i++) {
            int distRightL = abs(i-rightClosestL[i]);
            int distLeftR  = abs(i-leftClosestR[i]);

            if(rightClosestL[i] == leftClosestR[i])
                result[i] = '.';
            else if(rightClosestL[i] == -1)
                result[i] = 'R';
            else if(leftClosestR[i] == -1)
                result[i] = 'L';
            else if(distLeftR == distRightL)
                result[i] = '.';
            else
                result[i] = distRightL < distLeftR ? 'L': 'R';
        }

        return result;
    }
};

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();

        vector<int> forces(n);

        int force = 0;
        for(int i = 0; i<n; i++) {
            if(dominoes[i] == 'R')
                force = n;
            else if(dominoes[i] == 'L')
                force = 0;
            else
                force = max(force-1, 0);

            forces[i] = force;
        }

        force = 0;
        for(int i = n-1; i>=0; i--) {
            if(dominoes[i] == 'L')
                force = n;
            else if(dominoes[i] == 'R')
                force = 0;
            else
                force = max(force-1, 0);

            forces[i] -= force;
        }

        string result(n ,'.');
        for(int i = 0; i<n; i++) {
            if(forces[i] < 0)
                result[i] = 'L';
            else if(forces[i] > 0)
                result[i] = 'R';
        }
        return result;

    }
};

class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        int n    = s.length();
        string result = "";
        for(int i = 0, j = 1; j<n; j++) {
            if(s[j] == '.') continue;

            int midPartLength = j-i-1;
            if(i > 0)
                result.push_back(s[i]);

            if(s[i] == s[j])
                result += string(midPartLength, s[i]);
            else if(s[i] == 'L' && s[j] == 'R')
                result += string(midPartLength, '.');
            else
                result += string(midPartLength/2, 'R') + string(midPartLength%2, '.') + string(midPartLength/2, 'L');
            i = j;
        }

        return result;
    }
};
