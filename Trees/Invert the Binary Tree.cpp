Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4

********************************************************************************************************************************************************************

void invert(TreeNode *root){
    if(root == NULL)return;
    TreeNode* temp = root->left;
    root->left = root->right;
    root ->right = temp;
    invert(root->left);
    invert(root->right);
}

TreeNode* Solution::invertTree(TreeNode* root) {
    invert(root);
    return root;
}
