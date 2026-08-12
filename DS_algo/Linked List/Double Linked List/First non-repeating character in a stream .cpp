class Solution {
public:
    string FirstNonRepeating(string s) {
        list<char> dl;
        vector<list<char>::iterator> mp(26);
        vector<bool> arr(26, false);
        string result = "";

        for(int i = 0; i<s.length(); i++) {
            char ch = s[i];
            int idx = ch-'a';

            if(arr[idx] == false) {
                dl.push_back(ch);
                mp[idx]   = --dl.end();
                arr[idx] = true;
            } else {
                if(mp[idx] != dl.end()) {
                    dl.erase(mp[idx]);
                    mp[idx] = dl.end();
                }
            }

            if(dl.empty())
                result.push_back('#');
            else
                result.push_back(dl.front());
        }

        return result;
    }
};

class Solution {
public:
    string FirstNonRepeating(string s){
        vector<int> freq(26, 0);
        queue<char> que;
        string result = "";

        for(char &ch : s) {
            int idx = ch-'a';
            freq[idx]++;

            que.push(ch);
            while(!que.empty() && freq[que.front()-'a'] > 1) {
                que.pop();
            }

            if(que.empty())
                result.push_back('#');
            else
                result.push_back(que.front());
        }
        return result;
    }
};
