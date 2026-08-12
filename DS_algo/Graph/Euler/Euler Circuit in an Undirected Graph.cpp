class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    vector<int> degree(V, 0);

	    for(int i = 0; i<V; i++) {

	        degree[i] = adj[i].size();

	    }

	    for(int i = 0; i<V; i++) {
	        if(degree[i] % 2 != 0) {
	            return false;
	        }
	    }

	    return true;
	}
};
