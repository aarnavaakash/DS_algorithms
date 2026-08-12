class Solution {
public:
    map<int, vector<int>> mp;
    int collectNodeWithHeight(TreeNode* root) {
        if(!root)
            return 0;

        int height = 1 + max(collectNodeWithHeight(root->left),
                             collectNodeWithHeight(root->right)
                             );

        mp[height].push_back(root->val);

        return height;
    }
    vector<vector<int>> findLeaves(TreeNode * root) {
        mp.clear();
        collectNodeWithHeight(root);

        vector<vector<int>> result;
        for(auto &it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
