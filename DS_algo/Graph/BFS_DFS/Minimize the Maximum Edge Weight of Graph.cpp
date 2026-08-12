class Solution {
public:
    typedef pair<int, int> P;

    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid) {

        queue<int> que;
        vector<bool> visited(n, false);

        que.push(0);
        visited[0] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(P &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if(w <= mid && !visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                return false;
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;

        int maxWt = 0;

        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w});
            maxWt = max(maxWt, w);
        }

        int result = INT_MAX;

        int l = 0;
        int r = maxWt;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canAllReachZero(n, adj, mid) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result == INT_MAX ? -1 : result;

    }
};

class Solution {
public:

    typedef pair<int, int> P;

    void dfs(int u, unordered_map<int, vector<P>>& adj, int mid, vector<bool>& visited) {
        visited[u] = true;

        for(auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if(w <= mid && !visited[v]) {
                visited[v] = true;
                dfs(v, adj, mid, visited);
            }
        }
    }

    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid) {

        vector<bool> visited(n, false);
        dfs(0, adj, mid, visited);

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                return false;
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;

        int maxWt = 0;

        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w});
            maxWt = max(maxWt, w);
        }

        int result = INT_MAX;

        int l = 0;
        int r = maxWt;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canAllReachZero(n, adj, mid) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result == INT_MAX ? -1 : result;

    }
};
