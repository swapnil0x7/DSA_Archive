TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (p < root->val && q < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (p > root->val && q > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

int findDistance(TreeNode* root, int key) {
    if (root == nullptr) {
        return -1; // Key not found
    }

    if (root->val == key) {
        return 0; // Distance to itself is 0
    } else if (key < root->val) {
        int leftDist = findDistance(root->left, key);
        if (leftDist != -1) {
            return leftDist + 1; // Add 1 for the current node
        }
    } else {
        int rightDist = findDistance(root->right, key);
        if (rightDist != -1) {
            return rightDist + 1; // Add 1 for the current node
        }
    }

    return -1; // Key not found in this subtree
}

int Solution::solve(TreeNode* root, int x, int y) {
    TreeNode* lca = lowestCommonAncestor(root, x, y);
        
    int distX = findDistance(lca, x);
    int distY = findDistance(lca, y);

    return distX + distY;
}
