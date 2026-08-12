class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double>> pq;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i+1; j < arr.size(); j++) {
                double div = (double) arr[i] / arr[j];
                pq.push(vector<double>{div, (double)arr[i], (double)arr[j]});
                if(pq.size() > k)
                    pq.pop();
            }
        }

        auto vec  = pq.top();
        vector<int> result(2);
        result[0] = vec[1];
        result[1] = vec[2];
        return result;
    }
};

class Solution {
public:
    typedef vector<double> V;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<V, vector<V>, greater<V>> pq;

        for(int i = 0; i < n; i++)
            pq.push({1.0*arr[i]/arr.back(), (double)(i), (double)(n-1)});

        int smallest = 1;

        while(smallest < k) {
            V vec = pq.top();
            pq.pop();

            int i = vec[1];
            int j = vec[2]-1;

            pq.push({1.0*arr[i]/arr[j], (double)(i), (double)(j)});
            smallest++;
        }

        V vec = pq.top();
        int i = vec[1];
        int j = vec[2];
        return {arr[i], arr[j]};
    }
};
