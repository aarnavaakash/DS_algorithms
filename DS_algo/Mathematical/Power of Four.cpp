class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        while(n%4 == 0){
            n /= 4;
        }
        return n==1;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        int a = (log(n)/log(4));

        if(n == pow(4, a))
            return true;

        return false;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {

        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};
