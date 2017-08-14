Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

*****************************************************************************************************************************************************************************************************************************

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<int> r;
    vector<vector<int>> res;
    stack<TreeNode *> S;
    if(A == NULL )return res;
    r.push_back(A->val);
    res.push_back(r);
    stack<TreeNode*> temp;
    r.clear();
    bool ltor = true;
    if(A->left == NULL && A->right == NULL) return res;
    if(A->left) S.push(A->left);
    if(A->right) S.push(A->right);
   
    while(!S.empty()){

        TreeNode* cur = S.top();
        if(ltor){
        if(cur->right)temp.push(cur->right);
        if(cur->left)temp.push(cur->left);}
        if(!ltor){
        if(cur->left)temp.push(cur->left);
        if(cur->right)temp.push(cur->right);
        }
        r.push_back(cur->val);
        S.pop();
        if(S.empty()){
            res.push_back(r);
            r.clear();
            S = temp;
            while(!temp.empty())temp.pop();
            if(ltor)ltor = false;
            else ltor = true;
        }
    }
    return res;
}
