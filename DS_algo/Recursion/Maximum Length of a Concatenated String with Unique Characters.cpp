class Solution {
public:
    int maxLength(vector<string>& arr, string temp = "", int idx = 0) {
        unordered_set<char> st(begin(temp), end(temp));
        if(st.size() != temp.length()) return 0;

        int maxL = temp.length();
        for(int i = idx; i<arr.size(); i++) {
            maxL = max(maxL, maxLength(arr, temp+arr[i], i+1));
        }
        return maxL;
    }
};

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> result{""};
        int maxL = 0;

        for(const string& s : arr) {
            vector<string> vec;
            for(const string& t : result) {
                string temp = s+t;
                unordered_set<char> st(begin(temp), end(temp));
                if(st.size() == temp.length()) {
                    vec.push_back(temp);
                    maxL = max(maxL, (int)temp.length());
                }
            }
            result.insert(end(result), begin(vec), end(vec));
        }

        return maxL;
    }
};
