class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;

        while(num1 > 0 && num2 > 0) {
            count += num1/num2;

            num1 %= num2;

            swap(num1, num2);
        }

        return count;
    }
};

class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0)
            return 0;

        if(num1 < num2)
            swap(num1, num2);

        return num1/num2 + countOperations(num1%num2, num2);
    }
};

class Solution {
    public int countOperations(int num1, int num2) {
        int count = 0;

        while (num1 > 0 && num2 > 0) {
            count += num1 / num2;
            num1 %= num2;

            int temp = num1;
            num1 = num2;
            num2 = temp;
        }

        return count;
    }
}

class Solution {
    public int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0)
            return 0;

        if (num1 < num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }

        return num1 / num2 + countOperations(num1 % num2, num2);
    }
}
