class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string result;

        vector<bool> taken(26, false);
        vector<int> lastIndex(26);

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            lastIndex[ch-'a'] = i;
        }

        for(int i = 0; i < n; i++) {

            int idx = s[i] - 'a';

            if(taken[idx] == true) continue;

            while(result.length() > 0 && s[i] < result.back() && lastIndex[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(s[i]);
            taken[idx] = true;

        }

        return result;
    }
};

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        stack<char> st;

        vector<bool> taken(26, false);
        vector<int> lastIndex(26);

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            lastIndex[ch-'a'] = i;
        }

        for(int i = 0; i < n; i++) {

            int idx = s[i] - 'a';

            if(taken[idx] == true) continue;

            while(!st.empty()  && s[i] < st.top() && lastIndex[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            taken[idx] = true;

        }

        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));

        return result;
    }
};

class Solution {
public:
    string result = "";
    int n;
    int unique_characters;

    void solve(int idx, string s, string temp, unordered_set<char>& st) {
        if(idx >= n) {
            if(result == "")
                result = s;
            else if(temp.size() == unique_characters)
                result = result > temp ? temp : result;

            return;
        }

        if(st.find(s[idx]) == st.end()) {
            temp.push_back(s[idx]);
            st.insert(s[idx]);
            solve(idx+1, s, temp, st);

            st.erase(s[idx]);
            temp.pop_back();
        }

        solve(idx+1, s, temp, st);
    }

    string removeDuplicateLetters(string s) {
        n = s.length();
        unordered_set<char> st;

        for(char &ch : s) {
            st.insert(ch);
        }
        unique_characters = st.size();

        st.clear();

        solve(0, s, "", st);

        return result;
    }
};
