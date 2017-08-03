Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3
   
**************************************************************************************************************

int mid(const vector<int> A , int st , int end){
    return ((st + end)/2);
} 
 
TreeNode* createTree(TreeNode* head,const vector<int> &A , int st , int end){
    if(st > end)return NULL;
    int i;
      i = mid(A , st , end);
      head = new TreeNode(A[i]);
      head ->left = createTree(head->left, A , st , i-1);
      head->right = createTree(head->right, A , i+1 ,end );
      return head;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
   TreeNode* res = createTree(res,A,0,A.size()-1);
     return res;
}
