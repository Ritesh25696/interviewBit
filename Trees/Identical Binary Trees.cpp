
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True

*************************************************************************************************************************

void inorder(TreeNode *A, vector<int> &res){
    if(A == NULL)return;
    inorder(A->left, res);
    res.push_back(A->val);
    inorder(A->right, res);
}
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    vector<int> a;
    vector<int> b;
    inorder(A,a);
    inorder(B,b);
    if(a.size() != b.size())return 0;
    else{
        for(int i=0 ; i<a.size() ; i++){
            if(a[i] != b[i])return 0;
        }
    }
    return 1;
}

*******************************************************************************************************************************

int Solution::isSameTree(TreeNode* A, TreeNode* B) {

    if(A == NULL && B == NULL)return true;
    if(A == NULL || B == NULL)return false;
    return ((A->val == B->val)&&(isSameTree(A->left,B->left))&&isSameTree(A->right,B->right));
}
