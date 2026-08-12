#include<bits/stdc++.h>
using namespace std;

int cutRod_memoization_I(vector<int>& prices, int n, vector<int>& t) {
    if(n <= 0)
        return 0;
    if(t[n] != -1)
        return t[n];

    int maxVal = -1;

    for(int i = 0; i<n; i++) {
        maxVal = max(maxVal, prices[i] + cutRod_memoization(prices, n-(i+1), t));
    }
    return t[n] = maxVal;
}

int cutRod_memoization_II(vector<int>& prices, int n, int W, vector<vector<int>>& t) {
    if(n <= 0 || W <= 0)
            return 0;

    if(t[n][W] != -1)
        return t[n][W];
    if(n <= W)
        return t[n][W] = max(prices[n-1] + cutRod_memoization_II(prices, n, W-n, t),
                                        cutRod_memoization_II(prices, n-1, W, t));
    else
        return t[n][W] = cutRod_memoization_II(prices, n-1, W, t);
}

int cutRod_bottom_up_I(vector<int>& prices) {
    int n = prices.size();
    vector<int> length(n);
    for(int i = 0; i<n; i++) {
        length[i] = i+1;
    }

    vector<vector<int>> t(n+1, vector<int>(n+1));
    for(int i = 0; i<n+1; i++) {
        for(int j = 0; j<n+1; j++) {
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else if(length[i-1] <= j) {
                t[i][j] = max(prices[i-1] + t[i][j-length[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][n];
}

int cutRod_bottom_up_II(vector<int>& arr)
{
   int n = arr.size();
   vector<int> val(n+1);
   vector<int> prices(n+1);
   for(int i = 1; i<n+1; i++) prices[i] = arr[i-1];
   val[0] = 0;
   int j, i;

    for(int j = 1; j<=n; j++) {
        int maxVal = -1;

        for(int i = 1; i<=j; i++) {
            int cost_to_cut_i                   = prices[i];
            int remaining_rod_length            = j-i;
            int remaining_rod_length_max_Profit = val[remaining_rod_length];
            maxVal = max(maxVal, cost_to_cut_i + remaining_rod_length_max_Profit);
        }
        val[j] = maxVal;
    }

   return val[n];
}

int main()
{
    vector<int> arr{1, 5, 8, 9, 10, 17, 17, 20};
    int n = arr.size();
    cout << "Maximum Obtainable Value is = " <<  cutRod_bottom_up_I(arr)   << endl;

    cout << "Maximum Obtainable Value is = " <<  cutRod_bottom_up_II(arr)    << endl;

    vector<int> t(n+1, -1);
    cout << "Maximum Obtainable Value is = " <<  cutRod_memoization_I(arr, n, t) << endl;

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout << "Maximum Obtainable Value is = " <<  cutRod_memoization_II(arr, n, n, dp) << endl;
    return 0;
}
