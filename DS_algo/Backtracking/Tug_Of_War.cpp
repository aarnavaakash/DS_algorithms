int minDiff = INT_MAX;
void solve(vector<int>& arr, int idx, int n, vector<int> set1, vector<int> set2, int sum1, int sum2) {
    if(idx == n) {
        minDiff = min(minDiff, abs(sum1-sum2));
        return;
    }

    if(set1.size() <= (n+1)/2) {
        set1.push_back(arr[idx]);
        solve(arr, idx+1, n, set1, set2, sum1+arr[idx], sum2);
        set1.pop_back();
    }

    if(set2.size() <= (n+1)/2) {
        set2.push_back(arr[idx]);
        solve(arr, idx+1, n, set1, set2, sum1, sum2+arr[idx]);
        set2.pop_back();
    }
}

int tugOfWar(vector<int>& arr) {
    int n = arr.size();
    vector<int> set1;
    vector<int> set2;

    int sum_set1 = 0;
    int sum_set2 = 0;

    solve(arr, 0, n, set1, set2, sum_set1, sum_set2);
    return minDiff;
}
