class Solution {
public:
    void traverseNaryTree(Node* root, vector<int>& result) {
        if(!root)
            return;

        result.push_back(root->val);

        for(int i = 0; i<root->children.size(); i++) {
            traverseNaryTree(root->children[i], result);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> result;
        traverseNaryTree(root, result);
        return result;
    }
};
