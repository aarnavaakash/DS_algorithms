class Solution {
public:
    unordered_map<TreeNode*, int> mp_rob;
    unordered_map<TreeNode*, int> mp_not_rob;
    int solve(TreeNode* root, bool parentRobbed) {
        if(!root)
            return 0;

        if(parentRobbed) {
            if(mp_rob.count(root))
                return mp_rob[root];
            return mp_rob[root] = solve(root->left, false) + solve(root->right, false);
        } else {
            if(mp_not_rob.count(root))
                return mp_not_rob[root];
            int rob     = root->val + solve(root->left, true) + solve(root->right, true);
            int not_rob = solve(root->left, false) + solve(root->right, false);
            return  mp_not_rob[root] = max(rob, not_rob);
        }
    }
    int rob(TreeNode* root) {
        mp_rob.clear();
        mp_not_rob.clear();
        return solve(root, false);
    }
};

class Solution {
public:

    pair<int, int> solve(TreeNode* root) {
        if(!root)
            return {0, 0};

        auto l = solve(root->left);
        auto r = solve(root->right);

        pair<int, int> result;

        result.first = root->val + l.second + r.second;

        result.second = max(l.first, l.second) + max(r.first, r.second);

        return result;
    }

    int rob(TreeNode* root) {
        if(!root)
            return 0;

        pair<int, int> result = solve(root);

        return max(result.first, result.second);
    }
};
