class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for(string &s : logs) {
            if(s == "../") {
                depth = max(0, depth-1);
            } else if(s == "./") {
                continue;
            } else {
                depth++;
            }
        }

        return depth;
    }
};

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (const string& currentOperation : logs) {
            if (currentOperation == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (currentOperation != "./") {
                st.push(currentOperation);
            }
        }

        return st.size();
    }
};
