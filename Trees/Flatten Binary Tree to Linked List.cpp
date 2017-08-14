Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.

**************************************************************************************************************

TreeNode* Solution::flatten(TreeNode* A) {
   if(A == NULL) return NULL;
   TreeNode *cur  = A;
   while(cur){
       if(cur->left){
       TreeNode *rm = cur->left;
       while(rm->right)rm = rm ->right;
           rm->right = cur->right;
           cur->right = cur ->left;
       cur->left = NULL;
       }
       
       cur = cur->right;
   }
   return A;
}
