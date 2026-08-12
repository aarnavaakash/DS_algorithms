class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;

        int result = 0;
        int counter = 0;
        while(n) {
            int r = n%2;
            result += (pow(2,counter)*!r);
            counter++;
            n = n>>1;
        }
        return result;
    }
};

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int mask = 1;

        while (mask < n) {
            mask = (mask << 1) | 1;
        }

        return n ^ mask;
    }
};

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int bits = floor(log2(n)) + 1;
        int mask = (1 << bits) - 1;

        return n ^ mask;
    }
};
