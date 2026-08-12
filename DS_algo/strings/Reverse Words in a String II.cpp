class Solution {
public:
    string reverseWords(string &str) {
        string result = "";
        int n = str.length();
        int i = n-1;
        int j = n-1;
        while(i >= 0) {
            if(str[i] == ' ') {
                result += str.substr(i+1, j-i) + " ";
                j = i-1;
            }
            i--;
        }
        result += str.substr(i+1, j-i);
        return result;
    }
};

class Solution {
public:
    string reverseWords(string &str) {
        string result = "";
        stringstream ss(str);
        string token = "";

        while(ss >> token) {
            result = token + " " + result;
        }

        return result.substr(0, result.length()-1);
    }
};
