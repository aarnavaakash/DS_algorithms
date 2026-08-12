class Solution {
public:

    bool checkBipartiteDFS(vector<int>adj[], int curr, vector<int>& color, int currColor) {
        color[curr] = currColor;

        for(int &v : adj[curr]) {

            if(color[v] == color[curr])
                return false;

            if(color[v] == -1) {

                int colorOfV = 1 - currColor;

                if(checkBipartiteDFS(adj, v, color, colorOfV) == false)
                    return false;
            }

        }

        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){

	    vector<int> color(V, -1);

	    for(int i = 0; i<V; i++) {
	        if(color[i] == -1) {
	            if(checkBipartiteDFS(adj, i, color, 1) == false)
	                return false;
	        }
	    }

	    return true;

	}

};

class Solution {
public:

    bool checkBipartiteBFS(vector<int>adj[], int curr, vector<int>& color, int currColor) {
        color[curr] = currColor;

        queue<int> que;
        que.push(curr);

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : adj[u]) {
                if(color[v] == color[u]) {
                    return false;
                } else if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }

        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){

	    vector<int> color(V, -1);

	    for(int i = 0; i<V; i++) {
	        if(color[i] == -1) {
	            if(checkBipartiteBFS(adj, i, color, 1) == false)
	                return false;
	        }
	    }

	    return true;

	}

};

class Solution {
public:
    int find(vector<int>& parent, int i) {
        if(parent[i] == i)
            return i;

        return parent[i] = find(parent, parent[i]);
    }

    void Union(vector<int>& parent, int x, int y) {
        int x_set = find(parent, x);
        int y_set = find(parent, y);

        if(x_set != y_set)
            parent[x_set] = y_set;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> parent(V);

        for(int i = 0; i<V; i++)
            parent[i] = i;

        for(int i = 0; i<V; i++) {

            for(int &x : graph[i]) {
                int u = i;
                int v = x;

                int x_set = find(parent, u);
                int y_set = find(parent, v);

                if(x_set == y_set)
                    return false;

                Union(parent, x, graph[i][0]);

            }
        }

        return true;
    }
};
