class MapSum {
public:
    unordered_map<string, int> mp;
    MapSum() {

    }

    void insert(string key, int val) {
        mp[key] = val;
    }

    int sum(string prefix) {
        int sum = 0;
        for(auto &it : mp) {
            if(it.first.find(prefix) == 0)
                sum += it.second;
        }
        return sum;
    }
};

class MapSum {
public:

    struct trieNode{
        char ch;
        int val = 0;
        trieNode* children[26];
    };

    trieNode* getTrieNode(char ch) {
        trieNode* temp = new trieNode;
        temp->ch = ch;
        for(int i = 0; i<26; i++) temp->children[i] = NULL;
        return temp;
    }

    void insertNode(string key, int val) {
        trieNode* pCrawl = root;

        for(char &ch : key) {
            if(pCrawl->children[ch-'a'] == NULL)
                pCrawl->children[ch-'a'] = getTrieNode(ch);

            pCrawl = pCrawl->children[ch-'a'];
        }

        pCrawl->val = val;
    }

    int findSum(trieNode* pCrawl) {
        if(!pCrawl)
            return 0;

        int sum = pCrawl->val;
        for(int i = 0; i<26; i++) {
            sum += findSum(pCrawl->children[i]);
        }
        return sum;
    }

    trieNode* root = NULL;
    MapSum() {
        root = getTrieNode('.');
    }

    void insert(string key, int val) {
        insertNode(key, val);
    }

    int sum(string prefix) {
        trieNode* pCrawl = root;
        for(char &ch : prefix) {
            if(pCrawl->children[ch-'a'] == NULL)
                return 0;
            pCrawl = pCrawl->children[ch-'a'];
        }

        return pCrawl == NULL ? 0 : findSum(pCrawl);
    }
};
