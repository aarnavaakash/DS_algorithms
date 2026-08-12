bool solve(Node* rootL, Node* rootR) {
    if(rootL == NULL && rootR == NULL) {
        return true;
    }

    if(rootL == NULL || rootR == NULL) {
        return false;
    }

    return solve(rootL->left, rootR->right) && solve(rootL->right, rootR->left);

}

bool IsFoldable(Node* root) {
    if(!root)
        return true;

    return solve(root->left, root->right);
}
