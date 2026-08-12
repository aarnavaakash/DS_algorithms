class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<P, vector<P>> pq;

        for(int i = 0; i<arr.size(); i++) {
            int diff = abs(x-arr[i]);

            pq.push({diff, arr[i]});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        sort(begin(result), end(result));
        return result;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;

        while(r-l >= k) {
            if(abs(arr[l]-x) <= abs(arr[r]-x))
                r--;
            else
                l++;
        }

        vector<int> result(arr.begin()+l, arr.begin()+l+k)
        return result;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size()-k;

        while(l < r) {
            int mid = l + (r-l)/2;

            if(x - arr[mid] > arr[mid+k] - x)
                l = mid+1;
            else {

                r = mid;
            }
        }

        vector<int> result(begin(arr)+l, begin(arr)+l+k);
        return result;
    }
};
