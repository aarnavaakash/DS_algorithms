************************************************************ C++ ************************************************************

class Solution {
public:
    int n;
    int t[1001][1001];

    bool predecessor(string& prev, string& curr) {
        int M = prev.length();
        int N = curr.length();

        if(M >= N || N-M != 1)
            return false;

        int i = 0, j = 0;
        while(i < M && j < N) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==M;
    }

    int lis(vector<string>& words, int prev_idx, int curr_idx) {
       if(curr_idx == n)
           return 0;

        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];

        int taken = 0;
        if(prev_idx == -1 || predecessor(words[prev_idx], words[curr_idx]))
            taken = 1 + lis(words, curr_idx, curr_idx+1);

        int not_taken = lis(words, prev_idx, curr_idx+1);

        if(prev_idx != -1)
            t[prev_idx][curr_idx] =  max(taken, not_taken);

        return max(taken, not_taken);

    }

    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        n = words.size();
        sort(begin(words), end(words), myFunction);
        return lis(words, -1, 0);
    }
};

class Solution {
public:
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();

        if(m >= n || n-m != 1)
            return false;

        int i = 0, j = 0;
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }

    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words), end(words), myFunction);

        vector<int> t(n, 1);
        int maxL = 1;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {

                if(predecessor(words[j], words[i])) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }

        return maxL;

    }
};

************************************************************ JAVA ************************************************************

class Solution {
    int n;
    int[][] t = new int[1001][1001];

    boolean predecessor(String prev, String curr) {
        int M = prev.length();
        int N = curr.length();

        if (M >= N || N - M != 1)
            return false;

        int i = 0, j = 0;
        while (i < M && j < N) {
            if (prev.charAt(i) == curr.charAt(j)) {
                i++;
            }
            j++;
        }
        return i == M;
    }

    int lis(String[] words, int prevIdx, int currIdx) {
        if (currIdx == n)
            return 0;

        if (prevIdx != -1 && t[prevIdx][currIdx] != -1)
            return t[prevIdx][currIdx];

        int taken = 0;
        if (prevIdx == -1 || predecessor(words[prevIdx], words[currIdx]))
            taken = 1 + lis(words, currIdx, currIdx + 1);

        int notTaken = lis(words, prevIdx, currIdx + 1);

        if (prevIdx != -1)
            t[prevIdx][currIdx] = Math.max(taken, notTaken);

        return Math.max(taken, notTaken);
    }

    int longestStrChain(String[] words) {
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) {
                t[i][j] = -1;
            }
        }

        n = words.length;
        Arrays.sort(words, (s1, s2) -> Integer.compare(s1.length(), s2.length()));
        return lis(words, -1, 0);
    }
}

class Solution {

    public int longestStrChain(String[] words) {
        int n = words.length;
        Arrays.sort(words, (s1, s2) -> Integer.compare(s1.length(), s2.length()));

        int[] t = new int[n];
        Arrays.fill(t, 1);
        int maxL = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (predecessor(words[j], words[i])) {
                    t[i] = Math.max(t[i], t[j] + 1);
                    maxL = Math.max(maxL, t[i]);
                }
            }
        }

        return maxL;
    }

    public boolean predecessor(String prev, String curr) {
        int M = prev.length();
        int N = curr.length();

        if (M >= N || N - M != 1)
            return false;

        int i = 0, j = 0;
        while (i < M && j < N) {
            if (prev.charAt(i) == curr.charAt(j)) {
                i++;
            }
            j++;
        }
        return i == M;
    }

}
