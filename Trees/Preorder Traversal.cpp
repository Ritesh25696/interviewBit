Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

********************************************************************************************************************************

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    if(A == NULL)return res;
    stack<TreeNode*> S;
    S.push(A);
    while(!S.empty()){
        TreeNode* temp = S.top();
        S.pop();
        res.push_back(temp->val);
        if(temp->right != NULL)S.push(temp->right);
        if(temp->left != NULL)S.push(temp->left);
    }
    return res;
}
