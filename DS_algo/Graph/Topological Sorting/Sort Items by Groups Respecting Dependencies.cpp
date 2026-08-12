**************************************** C++ ****************************************

class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, vector<int>& indegree)  {
	    queue<int> que;

	    for(int i = 0; i < adj.size(); i++) {
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

	    return result.size() == adj.size() ? result : vector<int>();
	}

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) {
            itemGraph[i] = vector<int>();
        }

        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(m, 0);
        for (int i = 0; i < m; ++i) {
            groupGraph[i] = vector<int>();
        }

        for (int i = 0; i < n; i++) {

            for (int prev : beforeItems[i]) {

                itemGraph[prev].push_back(i);
                itemIndegree[i]++;

                if (group[i] != group[prev]) {
                    int prevItemGroup = group[prev];
                    int currItemGroup = group[i];

                    groupGraph[prevItemGroup].push_back(currItemGroup);
                    groupIndegree[currItemGroup]++;
                }
            }
        }

        vector<int> itemOrder  = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);

        if (itemOrder.empty() || groupOrder.empty()) {
            return vector<int>();
        }

        unordered_map<int, vector<int>> groupToItemsInOrder;
        for (int item : itemOrder) {
            int itemGroup = group[item];
            groupToItemsInOrder[itemGroup].push_back(item);
        }

        vector<int> result;
        for (int group : groupOrder) {
            result.insert(result.end(), groupToItemsInOrder[group].begin(), groupToItemsInOrder[group].end());
        }

        return result;
    }
};

**************************************** JAVA ****************************************
class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {

        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        Map<Integer, List<Integer>> itemGraph = new HashMap<>();
        int[] itemIndegree = new int[n];
        for (int i = 0; i < n; ++i) {
            itemGraph.put(i, new ArrayList<>());
        }

        Map<Integer, List<Integer>> groupGraph = new HashMap<>();
        int[] groupIndegree = new int[m];
        for (int i = 0; i < m; ++i) {
            groupGraph.put(i, new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {

            for (int prev : beforeItems.get(i)) {

                itemGraph.get(prev).add(i);
                itemIndegree[i]++;

                if (group[i] != group[prev]) {
                    int prevItemGroup = group[prev];
                    int currItemGroup = group[i];

                    groupGraph.get(prevItemGroup).add(currItemGroup);
                    groupIndegree[currItemGroup]++;
                }

            }
        }

        List<Integer> itemOrder  = topoSort(itemGraph, itemIndegree);
        List<Integer> groupOrder = topoSort(groupGraph, groupIndegree);

        Map<Integer, List<Integer>> groupToItemsInOrder = new HashMap<>();
        for (Integer item : itemOrder) {
            int itemGroup = group[item];
            groupToItemsInOrder.computeIfAbsent(itemGroup, k -> new ArrayList<>()).add(item);
        }

        List<Integer> answerList = new ArrayList<>();
        for (int groupIndex : groupOrder) {
            answerList.addAll(groupToItemsInOrder.getOrDefault(groupIndex, new ArrayList<>()));
        }

        return answerList.stream().mapToInt(Integer::intValue).toArray();
    }

    private List<Integer> topoSort(Map<Integer, List<Integer>> adj, int[] indegree) {

        Queue<Integer> que = new LinkedList<>();
        for (int i = 0;i<indegree.length;i++) {
            if (indegree[i] == 0) {
                que.add(i);
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!que.isEmpty()) {
            Integer curr = que.remove();
            result.add(curr);

            for (Integer v : adj.get(curr)) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.add(v);
                }
            }
        }

        return result.size() == adj.size() ? result : new ArrayList<>();
    }
}
