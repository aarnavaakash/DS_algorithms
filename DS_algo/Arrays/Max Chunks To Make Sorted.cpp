class Solution {
public:

    int maxChunksToSorted(vector<int>& arr) {
        int n     = arr.size();
        int maxE  = arr[0];
        int count = 0;

        for(int i = 0; i<n; i++) {
            maxE = max(maxE, arr[i]);
            if(maxE == i)
                count++;
        }
        return count;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]]=i;
        }

        int count=0;
        int end = 0;
        while(end < n) {

            for(int start = end; start <= end; start++)
                end = max(end, mp[start]);
            end++;
            count++;
        }
        return count;
    }
};
