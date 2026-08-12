class Solution {
public:
    string simplifyPath(string path) {
        string token = "";

        stringstream ss(path);
        stack<string> st;

        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;

            if (token != "..")
                st.push(token);
            else if (!st.empty())
                st.pop();
        }

        string result = "";

        while(!st.empty()){
            result="/"+st.top()+result;
            st.pop();
        }

        if(result.length()==0)
            result="/";

        return result;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";

        stringstream ss(path);
        vector<string> st;

        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;

            if (token != "..")
                st.push_back(token);
            else if (!st.empty())
                st.pop_back();
        }

        string result = "";

        for(auto &token : st) {
            result += "/" + token;
        }

        return result.empty() ? "/" : result;
    }
};
