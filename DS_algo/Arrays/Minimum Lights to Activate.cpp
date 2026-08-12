int Solution::solve(vector<int> &A, int B) {
    int n     = A.size();
    int steps = 0;

    for(int i = 0; i<n;) {
        bool found = false;

        int j = min(n-1, i+B-1);
        for(; j>=max(0, i-B+1); j--) {
            if(A[j] == 1) {
                steps++;
                found = true;
                break;
            }
        }

        if(!found) return -1;

        i = j + B;
    }

    return steps;
}
