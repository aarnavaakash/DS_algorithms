class Solution {
    public:
    vector<vector<Node*>> paths;
    void storeRootToLeaf(Node* root, vector<Node*>& temp) {
        if(!root) {
            return;
        }

        temp.push_back(root);
        if(!root->left && !root->right) {
            paths.push_back(temp);
        }
        storeRootToLeaf(root->left, temp);
        storeRootToLeaf(root->right, temp);
        temp.pop_back();
    }

    int printKDistantfromLeaf(Node* root, int k) {
        paths.clear();
        vector<Node*> temp;
    	storeRootToLeaf(root, temp);
    	unordered_set<Node*> st;

    	for(vector<Node*> &vec : paths) {
    	    int n = vec.size();
    	    if(n - k > 0) {
    	        st.insert(vec[n-k-1]);
    	    }
    	}

    	return st.size();
    }
};

class Solution {
    public:

    void solve(Node* root, int level, unordered_set<Node*>& result, vector<Node*>& path, int& k) {
        if(!root) {
            return;
        }

        path.push_back(root);
        if(!root->left && !root->right) {
            if(level - k >= 0) {
                result.insert(path[level-k]);
            }
        }

        solve(root->left, level+1, result, path, k);
        solve(root->right, level+1, result, path, k);
        path.pop_back();
    }

    int printKDistantfromLeaf(Node* root, int k) {
        vector<Node*> path;
        unordered_set<Node*> result;

    	solve(root, 0, result, path, k);

    	return result.size();
    }
};
