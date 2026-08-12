class Solution {
public:
    vector<string> helper(int n) {
        if(n == 1) {
            return {"0", "1"};
        }

        vector<string> temp = helper(n-1);

        vector<string> padded;

        for(int i = 0; i<temp.size(); i++) {
            padded.push_back("0" + temp[i]);
        }

        for(int i = temp.size()-1; i >= 0; i--) {
            padded.push_back("1" + temp[i]);
        }

        return padded;
    }

    vector<int> grayCode(int n) {
        vector<string> result = helper(n);

        vector<int> finalR;

        for(string &s : result) {
            bitset<32> bt(s);
            finalR.push_back(bt.to_ulong());
        }
        return finalR;
    }
};

class Solution {
public:
    vector<int> result;
    void helper(bitset<32>& bt, int n) {
        if(n == 0) {

            result.push_back(bt.to_ulong());
            return;
        }

        helper(bt, n-1);

        bt.flip(n-1);

        helper(bt, n-1);
    }

    vector<int> grayCode(int n) {
        bitset<32> bt;

        result.clear();

        helper(bt, n);

        return result;
    }
};
