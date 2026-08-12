class Solution {
public:
    int totalMoney(int n) {
        int result = 0;

        int monday_money = 1;

        while(n > 0) {

            int money = monday_money;
            for(int day = 1; day <= min(n, 7); day++) {
                result += money++;
            }

            n            -= 7;
            monday_money += 1;
        }

        return result;

    }
};

class Solution {
public:
    int totalMoney(int n) {
        int items  = n / 7;
        int first  = 28;
        int last   = 28 + (items - 1) * 7;

        int arithmeticSum = items * (first + last) / 2;

        int monday_money = 1 + items;
        int finalWeek    = 0;

        for (int day = 1; day <= (n % 7); day++) {
            finalWeek += monday_money++;
        }

        return arithmeticSum + finalWeek;
    }
};
