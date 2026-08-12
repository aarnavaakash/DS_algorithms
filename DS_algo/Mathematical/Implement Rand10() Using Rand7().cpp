class Solution {
public:
    int rand10() {

        int row;
        int col;

        int num;
        do{
            row = rand7();
            col = rand7();

            num = (row-1)*7 + col;
        }while(num > 40);

        return ((num-1)%10) + 1;
    }
};

class Solution {
public:
    int rand10() {
        int v1 = 11, v2 = 7;

        while(v1 > 5) {
            v1 = rand7();
        }

        while(v2 == 7) {
            v2 = rand7();
        }

        if(v2 < 4) {
            return v1;
        }

        return v1+5;
    }
};
