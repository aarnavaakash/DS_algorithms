class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        int i = n-1;
        while(i >=0 && s[i] == ' ')
            i--;

        int length = 0;
        for(; i>=0; i--) {
            if(s[i] == ' ')
                break;
            length++;
        }
        return length;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {

        s.erase(s.find_last_not_of(' ') + 1);

        int lastSpace = s.find_last_of(' ');

        return lastSpace == string::npos ? s.length() : s.length() - lastSpace - 1;

    }
};
