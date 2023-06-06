bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1 == NULL and root2 == NULL)
        return true;
    
    if((root1 == NULL and root2 != NULL) or (root1 != NULL and root2 == NULL))
        return false;

    return (root1->data == root2->data and identicalTrees(root1->left, root2->left) and identicalTrees(root1->right, root2->right));
}
