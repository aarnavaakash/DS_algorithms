class Solution {
public:
    void pushAdjacentWords(unordered_map<string, bool>& mp, queue<string>& que, string curr) {
        int n = curr.length();
        for(int i = 0; i<n; i++) {
            char temp = curr[i];

            for(char ch = 'a'; ch<='z'; ch++) {
                curr[i] = ch;
                if(mp.find(curr) != mp.end() && mp[curr] ==  false) {
                    mp[curr] = true;
                    que.push(curr);
                }
            }
            curr[i] = temp;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0)
            return 0;

        unordered_map<string, bool> mp;

        for(string& word : wordList) {
            mp[word] = false;
        }

        if(mp.find(endWord) == mp.end())
            return 0;

        int level = 1;

        queue<string> que;
        que.push(beginWord);

        while(!que.empty()) {
            int n = que.size();
            while(n--) {
                string curr = que.front();
                que.pop();
                if(curr == endWord)
                    return level;
                pushAdjacentWords(mp, que, curr);
            }
            level++;
        }

        return 0;
    }
};
