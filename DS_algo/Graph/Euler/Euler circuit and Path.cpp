class Solution {
public:

    void DFS(vector<int>adj[], int u, vector<bool>& visited) {
        visited[u] = true;

        for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
            if(visited[*it] == false) {
                DFS(adj, *it, visited);
            }
        }
    }

    bool isConnected(int V, vector<int>adj[]) {
        vector<bool> visited(V, false);

        int nonZeroDegreeVertex = -1;
        for(int i = 0; i<V; i++) {
            if(adj[i].size() != 0) {
                nonZeroDegreeVertex = i;
                break;
            }
        }

        DFS(adj, nonZeroDegreeVertex, visited);

        for(int i = 0; i<V; i++) {
            if(visited[i] == false && adj[i].size() > 0)
                return false;
        }
        return true;
    }

	int isEularCircuit(int V, vector<int>adj[]){

	    if(isConnected(V, adj) == false) {
	        return 0;
	    }

	    int oddCount = 0;
	    for(int i = 0; i<V; i++) {
	        if(adj[i].size()%2 != 0) {
	            oddCount++;
	        }
	    }

        if (oddCount > 2)
            return 0;

        if(oddCount == 2) {
            return 1;
        }

        return 2;

	}
};
