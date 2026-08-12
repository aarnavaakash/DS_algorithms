class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;

        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }

        int n = nums.size();

        string result= "";

        for(int number = 0; number <= 65536; number++) {
            if(st.find(number) == st.end()) {
                result = bitset<16>(number).to_string();
                break;
            }
        }

        return result.substr(16-n);

    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;

        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }

        int n = nums.size();

        string result= "";

        for(int number = 0; number <= n; number++) {
            if(st.find(number) == st.end()) {
                result = bitset<16>(number).to_string();
                break;
            }
        }

        return result.substr(16-n);

    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        string result;

        for(int i = 0; i<n; i++) {
            char ch = nums[i][i];

            result += (ch == '0') ? "1" : "0";
        }

        return result;
    }
};
