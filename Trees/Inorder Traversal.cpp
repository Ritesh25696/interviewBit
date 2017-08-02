Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.

********************************************************************************************************************

vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> S;
    TreeNode *cur = A;
    vector<int> res;
    while(cur != NULL){
        S.push(cur);
        cur = cur->left;
    }
    while(!S.empty()){
        TreeNode *t = S.top();
        res.push_back(t->val);
        S.pop();
        if(t->right != NULL){
            cur = t->right;
            while(cur != NULL){
                S.push(cur);
                cur = cur->left;
            }
        }
    }
    return res;
}
