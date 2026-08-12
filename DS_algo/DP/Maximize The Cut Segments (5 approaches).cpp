#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSeg1(int N, int x, int y, int z) {
    int maxR = 0;
    for(int a = 0; a<=N; a++) {
        for(int b = 0; b<=N; b++) {
            int cz    = N-(a*x + b*y);
            if(cz < 0) {
                break;
            }
            double c  = double(cz)/double(z);
            if(c == int(c)) {
                maxR = max(maxR, a+b+(int)c);
            }
        }
    }
    return maxR;
}

int maxSeg2(vector<int> pieces, int n, int Sum) {
    vector<vector<int>> t(n+1, vector<int>(Sum+1));
    for(int col = 0; col<Sum+1; col++) {
        t[0][col] = INT_MIN;
    }

    for(int row = 1; row<n+1; row++) {
        t[row][0] = 0;
    }

    for(int col = 1; col<Sum+1; col++) {
        if(col%pieces[0] == 0)
            t[1][col] = col/pieces[0];
        else
            t[1][col] = INT_MIN;
    }

    for(int i = 2; i<n+1; i++) {
        for(int j = 1; j<Sum+1; j++) {
            if(pieces[i-1] <= j)
                t[i][j] = max(1 + t[i][j-pieces[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum] < 0 ? 0 : t[n][sum];
}

int maxSeg3(int a, int b, int c, int N) {
    vector<int> t(N+1, -1);

    t[0] = 0;
    for(int i = 0; i<N+1; i++) {
        if(t[i] == -1)
            continue;
        if(i+a < N+1)
            t[i+a] = max(t[i+a], 1 + t[i]);
        if(i+b < N+1)
            t[i+b] = max(t[i+b], 1 + t[i]);
        if(i+c < N+1)
            t[i+c] = max(t[i+c], 1 + t[i]);
    }
    return t[N];
}

int maxSeg4(int N, int x, int y, int z, vector<int>& t) {
    if(N < 0)
        return INT_MIN;
    if(N == 0)
        return 0;
    if(t[N] != -1)
        return t[N];
    int a = 1 + maxSeg(N-x, x, y, z, t);
    int b = 1 + maxSeg(N-y, x, y, z, t);
    int c = 1 + maxSeg(N-z, x, y, z, t);

    return t[N] = max({a, b, c});
}

int maxSeg5(vector<int>& pieces, int n, int Sum) {
    vector<vector<int>> t(n+1, vector<int>(Sum+1));
    for(int i = 0; i<n+1; i++) {
        for(int j = 0; j<Sum+1; j++) {
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for(int i = 1; i<n+1; i++) {
        for(int j = 1; j<Sum+1; j++) {
            if(pieces[i-1] <= j) {
                if(pieces[i-1] == j || t[i][j-pieces[i-1]] != 0)
                    t[i][j] = max(1 + t[i][j-pieces[i-1]], t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][Sum];
}

int main() {
    int T, x, y, z, N;
    vector<int> vec(3);
    cin >> T;
    while(T--){
        cin >> N;
        cin >> x >> y >> z;
        int maxR = 0;
        cout << maxSeg1(N, x, y, z) << endl;

        vector<int> pieces(3);
        pieces[0] = x;
        pieces[1] = y;
        pieces[2] = z;
        cout << maxSeg2(pieces, 3, N) << endl;

        cout << maxSeg3(N, x, y, z) << endl;

        vector<int> t(N+1, -1);
        int result = maxSeg4(N, x, y, z, t);
        cout <<  result < 0 ? 0 : result << endl;

        cout << maxSeg5(pieces, 3, N) << endl;
    }
return 0;
}
