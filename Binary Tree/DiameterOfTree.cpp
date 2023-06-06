//Diameter is nothing but sum of maximum left height and maximum right height.

int findDiameter(TreeNode<int>* root, int &diameter){     
    if(!root) return 0;

    int leftHeight = findDiameter(root->left, diameter);
    int rightHeight = findDiameter(root->right, diameter);

    diameter = max(diameter, leftHeight+rightHeight);
    
    return max(leftHeight, rightHeight) + 1;
}


int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = 0;
    findDiameter(root, diameter);
    return diameter;
}
