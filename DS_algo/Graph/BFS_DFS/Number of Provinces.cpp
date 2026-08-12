class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;

        for(int &v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, i, visited);
            }
        }

        return count;

    }
};

class Solution {
public:
    int n;
    void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;

        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1 && !visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }

        return count;

    }
};

class Solution {
public:

    void bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                bfs(adj, i, visited);
                count++;
            }
        }

        return count;

    }
};

class Solution {
public:
    int n;
    void bfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int v = 0; v<n; v++) {
                if(adj[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                bfs(isConnected, i, visited);
                count++;
            }
        }

        return count;

    }
};
