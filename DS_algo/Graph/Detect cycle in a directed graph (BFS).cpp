class Solution {
  public:

    bool isCyclic(int N, vector<int> adj[]) {
        queue<int> que;
	    vector<int> indegree(N, 0);
	    int count = 0;

	    for(int u = 0; u<N; u++) {
	        for(int &v : adj[u]) {
	            indegree[v]++;
	        }
	    }

	    for(int i = 0; i<N; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }

	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();

	        for(int &v : adj[u]) {
	            indegree[v]--;

	            if(indegree[v] == 0) {
	                que.push(v);
	                count++;
	            }

	        }
	    }

	    return count != N;
    }
};
