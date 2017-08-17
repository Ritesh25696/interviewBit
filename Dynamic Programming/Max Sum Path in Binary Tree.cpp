Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example :

Given the below binary tree,

       1
      / \
     2   3
Return 6.

************************************************************************************************************

int helper(TreeNode*A , int & res){
     if(A == NULL)return 0;
     int l = helper(A->left, res);
     int r = helper(A->right, res);
     int smax = max(max(r,l)+A->val,A->val);
     int gmax = max(smax,r+l+A->val);
     res = max(res,gmax);
     return smax;
 }
 
