class Solution {
public:
    string customSortString(string order, string str) {
        int count[26] = {0};

        for(char &x : str)
            count[x-'a']++;

        string result = "";
        for(char &ch : order) {
            while(count[ch-'a']--) {
                result.push_back(ch);
            }
        }

        for(char &ch : str) {
            if(count[ch-'a'] > 0) {
                result.push_back(ch);
            }
        }

        return result;
    }
};

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, -1);

        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;

        auto lambda = [&index](char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a'];
        };

        sort(begin(str), end(str), lambda);
        return str;

    }
};

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, INT_MAX);

        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;

        auto lambda = [&](char &ch1, char &ch2) {
            if(index[ch1-'a'] == index[ch2-'a'])
                return ch1 < ch2;

            return index[ch1-'a'] < index[ch2-'a'];
        };

        sort(begin(str), end(str), lambda);
        return str;

    }
};
