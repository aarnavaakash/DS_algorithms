class Solution {
public:
    bool dfs(map<int, vector<int>>& mp, int source, int destination, vector<bool>& inStack, vector<bool>& visited) {
        if(mp[source].size() == 0) {
            return source==destination;
        }
        inStack[source] = true;
        visited[source] = true;

        for(int &x : mp[source]) {
            if(inStack[x])
                return false;
            else if(!visited[x] && !dfs(mp, x, destination, inStack, visited))
                return false;
        }

        inStack[source] = false;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int, vector<int>> adj;
        int edgeCount = edges.size();
        for(int i = 0; i<edgeCount; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        if(adj[destination].size() != 0)
            return false;

        vector<bool> inStack(n, false);
        vector<bool> visited(n, false);
        return dfs(adj, source, destination, inStack, visited);
    }
};
