class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<vector<int>> result;
        unordered_map<int, int> mp;

        vector<int> top(K+1);

        for(int i = 0; i < N; i++) {
            int val = arr[i];

            mp[val]++;
            top[K] = val;

            int idx = K;

            for(int j = K-1; j >= 0; j--) {
                if(top[j] == val) {
                    idx = j;
                    break;
                }
            }

            for(int j = idx-1; j >= 0; j--) {
                if(mp[top[j]] < mp[top[j+1]]) {
                    swap(top[j], top[j+1]);
                } else if(mp[top[j]] == mp[top[j+1]] && (top[j] > top[j+1])) {
                    swap(top[j], top[j+1]);
                } else {
                    break;
                }
            }

            vector<int> temp;
            for (int j = 0; j < K && top[j] != 0; ++j) {
                temp.push_back(top[j]);
            }

            result.push_back(temp);
        }

        return result;
    }
};

typedef pair<int, int> P;
class Solution
{
  public:
    struct compare {
        bool operator() (P& p1, P& p2) {
            if(p1.second == p2.second)
                return p1.first > p2.first;

            return p1.second < p2.second;
        }
    };
    vector<int> kTop(int a[], int n, int k)
    {
        vector<int> result;
        unordered_map<int, int> mp;

        for(int i = 0; i<n; i++) {
            mp[a[i]]++;

            priority_queue<P, vector<P>, compare> pq(mp.begin(), mp.end());
            int n = k;
            while(!pq.empty() && n > 0) {
                auto curr = pq.top();
                result.push_back(curr.first);
                pq.pop();
                n--;
            }
        }

        return result;
    }
};
