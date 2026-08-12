class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();

        if(n < 3)
            return 0;

        int count = 0;
        for(int start = 0; start <= n-3; start++) {
            int diff = A[start+1]-A[start];

            for(int end = start+2; end<n; end++) {
                if(A[end]-A[end-1] == diff)
                    count++;
                else
                    break;
            }
        }

        return count;
    }
};

class Solution {
public:
    int count = 0;
    int slices(vector<int>& A, int i, vector<int>& t) {
        if(i < 2)
            return 0;
        if(t[i] != -1)
            return t[i];

        int c = 0;
        if(A[i] - A[i-1] == A[i-1]-A[i-2]) {
            c = 1 + slices(A, i-1, t);
            count += c;
        } else
            slices(A, i-1, t);

        return t[i] = c;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();

        if(n < 3)
            return 0;
        count = 0;

        vector<int> t(n, -1);
        slices(A, n-1, t);

        return count;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();

        if(n < 3)
            return 0;
        int count = 0;

        vector<int> t(n, 0);

        for(int i = 2; i<n; i++) {
            if(A[i]-A[i-1] == A[i-1]-A[i-2]) {
                t[i] = 1 + t[i-1];
                count += t[i];
            }
        }

        return count;
    }
};
