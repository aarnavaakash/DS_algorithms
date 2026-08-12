class Solution {
public:
    int nextGreaterElement(int n) {

        if(n < 10)
            return -1;

        string num = to_string(n);
        int l = num.length();
        int i = l-2;
        for(; i>=0; i--) {
            if(num[i] < num[i+1])
                break;
        }

        if(i < 0)
            return -1;

        for(int j = l-1; j>i; j--) {
            if(num[j] > num[i]) {
                swap(num[i], num[j]);
                break;
            }
        }

        sort(num.begin()+i+1, num.end());

        unsigned long long nextGr = stoll(num);

        if(nextGr <= n || nextGr > INT_MAX)
            return -1;

        return nextGr;
    }
};

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l    = s.length();
        next_permutation(s.begin(), s.end());
        long long num = stoll(s);

        if(num <= n || num > INT_MAX)
            return -1;
        return num;
    }
};
