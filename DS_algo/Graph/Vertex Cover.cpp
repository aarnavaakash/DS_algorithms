class Solution{
    public:

        int totalEdges = 0;
        bool isValidCover(int &k, int &n, vector<vector<int>> &adj) {

            int set = (1 << k) - 1;
            int limit = (1 << n);
            bool visited[n+1][n+1];

            while (set < limit) {

                memset(visited, 0, sizeof(visited));

                int count = 0;
                for(int j = 1, u = 1; u < n+1; j = j << 1, u++) {
                    if(set & j) {
                        for(int v = 1; v < n+1; v++) {

                            if(adj[u][v] == 1 && !visited[u][v]) {
                                visited[u][v] = true;
                                visited[v][u] = true;
                                count++;
                            }

                        }
                    }
                }

                if(count == totalEdges) {
                    return true;
                }

                int c = set & - set;
                int r = set + c;
                set = (((r ^ set) >> 2) / c) | r;
            }

            return false;

        }

        int vertexCover(int n, vector<pair<int, int>> &edges) {
            totalEdges = edges.size();

            vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

            for(auto &it : edges) {
                int u = it.first;
                int v = it.second;

                adj[u][v] = 1;
                adj[v][u] = 1;
            }

            int low = 1, high = n;
            int result = n;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (isValidCover(mid, n, adj)) {
                    result = mid;
                    high = mid-1;
                } else {
                    low = mid + 1;
                }
            }
            return result;
        }
};
