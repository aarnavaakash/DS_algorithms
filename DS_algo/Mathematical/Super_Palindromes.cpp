typedef unsigned long long ull;
class Solution {
public:
    bool isPallindrome(ull n) {
        ull num = n, rev = 0;
        while(num) {
            rev = rev*10 + num%10;
            num /= 10;
        }

        return rev == n;
    }

    ull getNextPallindrome(ull num, ull a) {
        while(a > 0) {
            num = (num*10) + (a%10);
            a /= 10;
        }
        return num;
    }

    int superpalindromesInRange(string left, string right) {
        ull l     = stoull(left);
        ull r     = stoull(right);
        ull sqr_l = sqrt(l);
        ull sqr_r = sqrt(r);
        int count = 0;

        ull pal_number;

        for(ull i = 1; (pal_number = getNextPallindrome(i, i/10)) <= sqr_r; i++) {

            if(pal_number >= sqr_l && pal_number <= sqr_r && isPallindrome(pal_number*pal_number))
                count++;

            pal_number = getNextPallindrome(i, i);

            if(pal_number >= sqr_l && pal_number <= sqr_r && isPallindrome(pal_number*pal_number))
                count++;
        }

        return count;

    }
};
