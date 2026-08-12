string removeDupUsingStack(string S) {
        stack<char> st;

        for(int i = S.length()-1; i>=0; i--) {
            if(st.empty() || st.top() != S[i])
                st.push(S[i]);
            else
                st.pop();
        }

        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }

class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";

        for(char &ch : s) {
            if(result.empty() || result.back() != ch) {
                result.push_back(ch);
            } else {
                result.pop_back();
            }
        }

        return result;
    }
};
