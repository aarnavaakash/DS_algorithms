class Solution {
	public:

	vector<int> topoSort(int N, vector<int> adj[])  {
	    queue<int> que;
	    vector<int> indegree(N, 0);

	    for(int u = 0; u<N; u++) {
	        for(int &v : adj[u]) {
	            indegree[v]++;
	        }
	    }

	    for(int i = 0; i<N; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	        }
	    }

	    vector<int> result;
	    while(!que.empty()) {
	        int u = que.front();
	        result.push_back(u);
	        que.pop();

	        for(int &v : adj[u]) {
	            indegree[v]--;

	            if(indegree[v] == 0) {
	                que.push(v);
	            }

	        }
	    }

	    return result;
	}
};
