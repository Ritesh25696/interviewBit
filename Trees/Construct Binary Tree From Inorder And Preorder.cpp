Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

******************************************************************************************************************
int findindex(vector<int>& inorder, int k , int st , int end){
    for(int i=st ; i<=end ; i++){
        if(inorder[i] == k) return i;
    }
} 
 
TreeNode* check(vector<int>& preorder, vector<int>& inorder , int st ,int end , int* p){
    if(st > end)return NULL;
    int in = findindex(inorder , preorder[*p], st ,end);
    TreeNode * temp = new TreeNode(preorder[(*p)++]);
    temp->left = check(preorder, inorder , st , in-1 ,p );
    temp->right = check(preorder, inorder , in+1 , end ,p);
    return temp;
} 
 
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    int p = 0;
    return check(preorder , inorder , 0 , preorder.size()-1, &p);
}
