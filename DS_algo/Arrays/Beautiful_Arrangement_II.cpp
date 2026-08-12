class Solution {
public:
    vector<int> constructArray(int n, int k) {

        vector<int> result(n);
        int l = 1, r = k+1;
        int i = 0;

        while(l <= r) {
            if(i%2 == 0)
                result[i++] = l++;
            else
                result[i++] = r--;
        }

        for(int x = k+2; x<=n; x++)
            result[i++] = x;

        return result;
    }
};
