class Solution {
public:
    int maxDepth(string s) {
        int result = 0;

        stack<char> st;

        for (char& ch : s) {

            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                st.pop();
            }

            result = max(result, (int)st.size());
        }

        return result;
    }
};

class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int openBrackets = 0;

        for (char &ch : s) {
            if (ch == '(') {
                openBrackets++;
            } else if (ch == ')') {
                openBrackets--;
            }

            result = max(result, openBrackets);
        }

        return result;
    }
};
