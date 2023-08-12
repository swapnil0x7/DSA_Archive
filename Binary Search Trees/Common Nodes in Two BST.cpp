int mod = 1e9+7;

void inorder(TreeNode* root, unordered_set<int> &s){
    if(!root) return;

    inorder(root->left, s);
    s.insert(root->val);
    inorder(root->right, s);
}

void check(TreeNode* root, unordered_set<int> &s, int &sum){
    if(!root) return;

    if(s.find(root->val) != s.end())
        sum = (sum % mod + root->val) % mod;
    
    check(root->left, s, sum);
    check(root->right, s, sum);
}
 
int Solution::solve(TreeNode* A, TreeNode* B) {
    unordered_set<int> s;

    inorder(A, s);
    
    int sum = 0;
    check(B, s, sum);
    return sum;
}
