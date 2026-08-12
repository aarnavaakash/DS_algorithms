***********************************    C++    ***********************************

class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {

        if(start > end) {
            return {NULL};
        }

        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        vector<TreeNode*> result;
        for(int i = start; i <= end; i++) {

            vector<TreeNode*> leftList  = solve(start, i-1);
            vector<TreeNode*> rightList = solve(i+1, end);

            for(TreeNode* leftRoot : leftList) {

                for(TreeNode* rightRoot : rightList) {

                    TreeNode* root = new TreeNode(i);
                    root->left  = leftRoot;
                    root->right = rightRoot;

                    result.push_back(root);

                }

            }

        }

        return result;

    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};

class Solution {
public:

    map<pair<int, int>, vector<TreeNode*>> mp;

    vector<TreeNode*> solve(int start, int end) {

        if(start > end) {
            return {NULL};
        }

        if(start == end) {
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        if(mp.find({start, end}) != mp.end())
            return mp[{start, end}];

        vector<TreeNode*> result;
        for(int i = start; i <= end; i++) {

            vector<TreeNode*> leftList  = solve(start, i-1);
            vector<TreeNode*> rightList = solve(i+1, end);

            for(TreeNode* leftRoot : leftList) {

                for(TreeNode* rightRoot : rightList) {

                    TreeNode* root = new TreeNode(i);
                    root->left  = leftRoot;
                    root->right = rightRoot;

                    result.push_back(root);

                }

            }

        }

        return mp[{start, end}] = result;

    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};

**********************************************************************    JAVA    **********************************************************************

class Solution {
    Map<Pair<Integer, Integer>, List<TreeNode>> memo;
    public List<TreeNode> allPossibleBST(int start, int end) {
        List<TreeNode> res = new ArrayList<>();
        if (start > end) {
            res.add(null);
            return res;
        }
        if (memo.containsKey(new Pair<>(start, end))) {
            return memo.get(new Pair<>(start, end));
        }

        for (int i = start; i <= end; ++i) {
            List<TreeNode> leftSubTrees = allPossibleBST(start, i - 1);
            List<TreeNode> rightSubTrees = allPossibleBST(i + 1, end);

            for (TreeNode left: leftSubTrees) {
                for (TreeNode right: rightSubTrees) {
                    TreeNode root = new TreeNode(i, left, right);
                    res.add(root);
                }
            }
        }
        memo.put(new Pair<>(start, end), res);
        return res;
    }

    public List<TreeNode> generateTrees(int n) {
        memo = new HashMap<>();
        return allPossibleBST(1, n);
    }
}
