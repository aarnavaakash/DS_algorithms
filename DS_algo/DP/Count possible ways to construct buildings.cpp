class Solution{
	public:
	int t[100001][2];
	int M = 1e9 + 7;

	int space    = 0;
	int building = 1;

	int solve(int n, int status) {
	    if(n == 0)
	        return 1;

	    if(t[n][status] != -1)
	        return t[n][status];

	    if(status == building)
	        return t[n][status] = solve(n - 1, space) % M;

	    else
	        return t[n][status] = (solve(n - 1, building) % M + solve(n - 1, space) % M) % M;

	   return -1;
	}

	int TotalWays(int N) {
	    memset(t, -1, sizeof(t));

	    long long x = (solve(N - 1, building) % M + solve(N - 1, space) % M) % M;

	    return (x * x) % M;
	}
};

class Solution{
	public:
	int M        = 1e9 + 7;
	int space    = 0;
	int building = 1;

	int TotalWays(int N) {
	    vector<vector<int>> t(N, vector<int>(2));

        for(int j = 0; j < 2; j++) {
            t[0][j] = 1;
        }

        for(int i = 1; i < N; i++) {
            for(int j = 0; j < 2; j++) {

                if(j == building) {
                    t[i][j] = t[i-1][space] % M;
                } else {
                    t[i][j] = (t[i-1][space] % M + t[i-1][building] % M) % M;
                }
            }
        }

        long long result = (t[N - 1][building] % M + t[N - 1][space] % M) % M;

        return (int) (result * result % M);
	}
};
