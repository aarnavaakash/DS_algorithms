class Solution {
public:
    string temp;

    void multiplyNum(int& num, vector<int>& result, int& size, int cross) {
        int carry = 0;

        for(int i = temp.length()-1; i >= 0; i--) {
            int p            = (num*(temp[i]-'0')) + carry + result[cross];
            result[cross++]  = p%10;
            carry            = p/10;
        }

        while(carry) {
            result[cross++] = carry%10;
            carry          /= 10;
        }

        size = cross;
    }

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int m = num1.length();
        int n = num2.length();

        if(m > n) {
            return multiply(num2, num1);
        }

        vector<int> result(m+n, 0);
        temp = num2;
        int size = 0;

        int cross = 0;
        for(int i = m-1; i>=0; i--) {
            int num = num1[i]-'0';
            multiplyNum(num, result, size, cross);
            cross++;
        }

        string ans = "";
        for(int i = size-1; i>=0; i--)
            ans.push_back(result[i]+'0');

        return ans;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        int sign = 1;

        if (num1[0] == '-') {
            sign *= -1;
            num1 = num1.substr(1);
        }

        if (num2[0] == '-') {
                sign *= -1;
                num2 = num2.substr(1);
        }

        int n1 = num1.size();
        int n2 = num2.size();
        if (n1 == 0 || n2 == 0) return "0";

        vector<int> result(n1 + n2, 0);

        int i_n1 = 0;
        int i_n2 = 0;

        for (int i=n1-1; i>=0; i--) {
            int carry = 0;
            int n1 = num1[i] - '0';

            i_n2 = 0;

            for (int j=n2-1; j>=0; j--) {

                int n2 = num2[j] - '0';

                int sum = n1*n2 + result[i_n1 + i_n2] + carry;

                carry = sum/10;

                result[i_n1 + i_n2] = sum % 10;

                i_n2++;
            }

            if (carry > 0)
                result[i_n1 + i_n2] += carry;

            i_n1++;
        }

        int i = result.size() - 1;
        while (i>=0 && result[i] == 0) i--;

        if (i == -1)
            return "0";

        string s = "";
        while (i >= 0) {
            s.push_back(result[i]+'0');
            i--;
        }

        if (sign == -1)
            return "-"+s;

        return s;

    }
};
