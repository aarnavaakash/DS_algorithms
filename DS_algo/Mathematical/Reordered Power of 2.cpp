class Solution {
public:
    string getSortedStr(int n) {
        string s = to_string(n);
        sort(begin(s), end(s));
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string s = getSortedStr(n);

        for(int p = 0; p <= 29; p++) {
            if(s == getSortedStr(1 << p)) {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    unordered_set<string> st;
    void buildSet() {

        for(int p = 0; p <= 29; p++) {
            string s = to_string(1 << p);
            sort(begin(s), end(s));
            st.insert(s);
        }
    }

    bool reorderedPowerOf2(int n) {
        if(st.empty()) {
            buildSet();
        }

        string s = to_string(n);
        sort(begin(s), end(s));

        return st.count(s);
    }
};

class Solution {
public:
    vector<int> getVectorCountFormat(int n) {
        vector<int> vec(10, 0);

        while(n) {
            vec[n%10]++;
            n /= 10;
        }

        return vec;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> input = getVectorCountFormat(n);

        for(int p = 0; p <= 29; p++) {
            if(input == getVectorCountFormat(1 << p)) {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    int getVectorCountFormat(int n) {
        int num = 0;

        while(n) {
            num += pow(10, n%10);
            n /= 10;
        }

        return num;
    }

    bool reorderedPowerOf2(int n) {
        int input = getVectorCountFormat(n);

        for(int p = 0; p <= 29; p++) {
            if(input == getVectorCountFormat(1 << p)) {
                return true;
            }
        }

        return false;
    }
};
