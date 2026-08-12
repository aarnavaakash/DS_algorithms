class Solution {
public:
    unordered_map<int, bool> mp;
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;

        if(mp.find(n) != mp.end())
            return mp[n];

        if(n%2 == 0 && isUgly(n/2))
            return mp[n] = true;
        else if(n%3 == 0 && isUgly(n/3))
            return mp[n] = true;
        else if(n%5 == 0 && isUgly(n/5))
            return mp[n] = true;

        return mp[n] = false;
    }
    int nthUglyNumber(int n) {
        mp.clear();
        int num = 1;
        while(n > 0) {
            if(isUgly(num)) {
                n--;
            }
            num++;
        }

        return num-1;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n+1);

        t[1] = 1;

        int i2;
        int i3;
        int i5;

        i2 = i3 = i5 = 1;

        for(int i = 2; i<=n; i++) {
            int i2th_ugly = t[i2] * 2;

            int i3rd_ugly = t[i3] * 3;

            int i5th_ugly = t[i5] * 5;

            t[i] = min({i2th_ugly, i3rd_ugly, i5th_ugly});

            if(t[i] == i2th_ugly)
                i2++;

            if(t[i] == i3rd_ugly)
                i3++;

            if(t[i] == i5th_ugly)
                i5++;
        }

        return t[n];
    }
};
