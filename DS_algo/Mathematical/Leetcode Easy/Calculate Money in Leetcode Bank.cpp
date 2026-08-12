class Solution {
public:
    int totalMoney(int n) {
        int result = 0;

        int monday_money = 1;

        while(n > 0) {

            int money = monday_money;
            for(int day = 1; day <= min(n, 7); day++) {
                result += money;
                money++;
            }

            n -= 7;
            monday_money++;
        }

        return result;
    }
};

class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7;

        int first = 28;
        int last  = 28 + (terms - 1) * 7;

        int result = terms * (first + last) / 2;

        int start_money = 1 + terms;

        for(int day = 1; day <= (n%7); day++) {
            result += start_money;
            start_money++;
        }

        return result;
    }
};

class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7;

        int first = 28;
        int last  = 28 + (terms - 1) * 7;

        int result = terms * (first + last) / 2;

        int remain = n%7;
        int first_term = (1 + terms);
        int last_term  = first_term + remain - 1;
        result += remain * (first_term + last_term) / 2;

        return result;
    }
};
