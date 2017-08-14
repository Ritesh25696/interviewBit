Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 
 
*********************************************************************************************************

int kthsmallestRes(TreeNode *root, int k, int &current) {
    if(root->left != NULL) {
        int res = kthsmallestRes(root->left, k, current);
        if(current == k) return res;
    }
    ++current;
    if(current == k)
        return root->val;

    if(root->right != NULL) {
        int res = kthsmallestRes(root->right, k, current);        
        if(current == k)
            return res;
    }    
} 

int Solution::kthsmallest(TreeNode* root, int k) {
    int level = 0;
    return kthsmallestRes(root, k, level);
    
}
