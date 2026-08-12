class Solution {
public:
    typedef pair<char, int> P;

    string frequencySort(string s) {
        vector<P> vec(123);

        for(char &ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq+1};
        }

        auto comp = [&](P &p1, P &p2) {
            return p1.second > p2.second;
        };

        sort(begin(vec), end(vec), comp);

        string result = "";

        for(int i = 0; i <= 122; i++) {
            result += string(vec[i].second, vec[i].first);
        }
        return result;
    }
};

class Solution {
public:
    typedef pair<char, int> P;
    struct comp {
        bool operator()(P &p1, P &p2) {
            return p1.second<p2.second;
        }
    };

    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;

        unordered_map<char, int> mp;
        for(char &ch : s) {
            mp[ch]++;
        }

        for(auto &it : mp) {
            pq.push({it.first, it.second});
        }

        string result = "";

        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();

            result += string(temp.second, temp.first);
        }
        return result;
    }
};
