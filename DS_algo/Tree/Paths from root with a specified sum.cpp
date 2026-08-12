class Solution
{
    public:
    vector<vector<int>> result;

    void solve(Node* root, int sum, vector<int>& temp, int curr_sum) {
        if(root == NULL) {
            return;
        }

        curr_sum += root->key;
        temp.push_back(root->key);

        if(sum == curr_sum) {
            result.push_back(temp);
        }

        solve(root->left, sum, temp, curr_sum);
        solve(root->right, sum, temp, curr_sum);
        temp.pop_back();
    }

    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<int> temp;
        solve(root, sum, temp, 0);

        return result;

    }
};
