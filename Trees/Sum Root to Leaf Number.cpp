Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

*****************************************************************************************************************************************************

int sum(TreeNode* root, int val){
    if(root == NULL){
        return 0;
    }
    val = (((val)*10) + (root->val))%1003;
    if(root->left == NULL && root->right == NULL){
        return val;
    }
    return (sum(root->left, val) + sum(root->right, val))%1003;
}

int Solution::sumNumbers(TreeNode* A) {
    return sum(A, 0);
}
