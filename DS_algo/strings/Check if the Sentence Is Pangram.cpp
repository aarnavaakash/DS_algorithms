class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26, 0);

        for(char &ch : sentence) {
            int index = ch - 'a';
            arr[index]++;
        }

        for(int &count : arr) {
            if(count == 0)
                return false;
        }

        return true;
    }
};

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> arr(26, 0);

        int count = 0;

        for(char &ch : sentence) {
            int index = ch - 'a';

            if(arr[index] == 0) {
                arr[index]++;
                count++;
            }
        }

        return count==26;
    }
};
