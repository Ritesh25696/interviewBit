Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.

************************************************************************************************************

int md(TreeNode *A , int depth){
    if(A == NULL)return 0;
    return  max(md(A->left,depth+1),md(A->right, depth+1))+1;
}
 
int Solution::maxDepth(TreeNode* A) {
    return md(A,0);
}
