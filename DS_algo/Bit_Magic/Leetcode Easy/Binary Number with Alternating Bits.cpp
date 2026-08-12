class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> b(n);
        int bits = log2(n);
        for(int i = 0; i<=bits; i++) {
            if(b[i] == b[i+1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int currBit = n % 2;
        n /= 2;

        while (n > 0) {
            if (currBit == n % 2)
                return false;

            currBit = n % 2;

            n /= 2;
        }

        return true;
    }
};

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int result = n ^ (n >> 1);

        return (result & (result + 1)) == 0;
    }
};
