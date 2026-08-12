class Solution {
public:

    void dfs(int node, unordered_map<int, vector<int>> &adj, int id, vector<int>& nodeId,
            unordered_map<int, set<int>>& mp, vector<bool>& visited) {
        visited[node] = true;
        mp[id].insert(node);
        nodeId[node] = id;

        for(int &ngbr : adj[node]) {
            if(!visited[ngbr]) {
                dfs(ngbr, adj, id, nodeId, mp, visited);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge :  connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(c+1, false);
        vector<int> nodeId(c+1);

        unordered_map<int, set<int>> mp;

        for(int node = 1; node <= c; node++) {
            if(!visited[node]) {
                int id = node;
                dfs(node, adj, id, nodeId, mp, visited);
            }
        }

        vector<int> result;

        for(auto &query : queries) {
            int type = query[0];
            int node = query[1];

            if(type == 1) {
                int id = nodeId[node];
                if(mp[id].count(node)) {
                    result.push_back(node);
                } else if(!mp[id].empty()) {
                    result.push_back(*mp[id].begin());
                } else {
                    result.push_back(-1);
                }
            } else {
                int id = nodeId[node];
                mp[id].erase(node);
            }

        }
        return result;
    }
};

class Solution {
public:

    void bfs(int start, unordered_map<int, vector<int>> &adj, int id,
             vector<int>& nodeId, unordered_map<int, set<int>>& mp,
             vector<bool>& visited) {

        queue<int> q;
        q.push(start);
        visited[start] = true;
        nodeId[start] = id;
        mp[id].insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int &ngbr : adj[node]) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    nodeId[ngbr] = id;
                    mp[id].insert(ngbr);
                    q.push(ngbr);
                }
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(c + 1, false);
        vector<int> nodeId(c + 1);
        unordered_map<int, set<int>> mp;

        for (int node = 1; node <= c; node++) {
            if (!visited[node]) {
                int id = node;
                bfs(node, adj, id, nodeId, mp, visited);
            }
        }

        vector<int> result;

        for (auto &query : queries) {
            int type = query[0];
            int node = query[1];

            if (type == 1) {
                int id = nodeId[node];
                if (mp[id].count(node)) {
                    result.push_back(node);
                } else if (!mp[id].empty()) {
                    result.push_back(*mp[id].begin());
                } else {
                    result.push_back(-1);
                }
            } else {
                int id = nodeId[node];
                mp[id].erase(node);
            }
        }

        return result;
    }
};

class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int Find(int x){
        if(x == parent[x])
            return x;

        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y){
        int x_par = Find(x);
        int y_par = Find(y);

        if(x_par == y_par)
            return;

        if(rank[x_par] > rank[y_par]){
            parent[y_par] = x_par;
            rank[x_par]++;
        }
        else if(rank[x_par] < rank[y_par]){
            parent[x_par] = y_par;
            rank[y_par]++;
        }
        else{
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> result;
        int n = connections.size();

        rank.resize(c+1, 0);
        parent.resize(c+1);
        for(int i = 1; i <= c; i++) {
            parent[i] = i;
        }

        for(auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            Union(u, v);
        }

        unordered_map<int, set<int>> mp;
        vector<int> nodeId(c+1);

        for(int i = 1;i <= c; i++){
            int par = Find(i);
            mp[par].insert(i);
            nodeId[i] = par;
        }

        for(auto& query : queries){
            int type = query[0];
            int node = query[1];
            int id = nodeId[node];

            if(type == 1) {
                if(mp[id].find(node) != mp[id].end()){
                    result.push_back(node);
                } else if(!mp[id].empty()) {
                    result.push_back(*mp[id].begin());
                } else {
                    result.push_back(-1);
                }
            }
            else {
                mp[id].erase(node);
            }
        }

        return result;

    }
};
