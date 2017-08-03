Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

************************************************************************************************************************************************************************

void check(TreeNode* A, int B , vector<int> &res , vector<vector<int>> &result){
    if(A == NULL) return;
    B -= A->val;
    res.push_back(A->val);
    if(B==0 && A->right == NULL && A->left == NULL){
        
        result.push_back(res);
        res.pop_back();
        return;}
    if( A->right == NULL && A->left == NULL){
        res.pop_back();
        return;}
    check(A->left,B,res,result);
    check(A->right,B,res,result);
    res.pop_back();
} 

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<int> res;
    vector<vector<int>> result;
    check(root , sum , res,result);
    return result;
    
}
