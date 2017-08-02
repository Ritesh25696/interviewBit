Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.

***************************************************************************************************************************************************

vector<int> Solution::postorderTraversal(TreeNode* root) {
  stack<TreeNode*> nodeStack;
            vector<int> result;
            //base case
            if(root==NULL)
                return result;
            nodeStack.push(root);
            while(!nodeStack.empty()) {
                TreeNode* node= nodeStack.top();  
                result.push_back(node->val);
                nodeStack.pop();
                if(node->left)
                    nodeStack.push(node->left);
                if(node->right)
                    nodeStack.push(node->right);
            }
            reverse(result.begin(),result.end());
            return result;

}
