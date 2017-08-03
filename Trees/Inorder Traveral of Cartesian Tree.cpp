Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
      
********************************************************************************************************************************      

int max(vector<int> A , int st , int end){
    int index , max = INT_MIN;
    for(int i= st ; i<=end ; i++){
        if(A[i] > max){
            max = A[i];
            index = i;
        }
    }
    return index;
} 
 
TreeNode* createTree(TreeNode* head, vector<int> &A , int st , int end){
    if(st > end)return NULL;
    int i;
      i = max(A , st , end);
      head = new TreeNode(A[i]);
      head ->left = createTree(head->left, A , st , i-1);
      head->right = createTree(head->right, A , i+1 ,end );
      return head;
    
    
}

TreeNode* Solution::buildTree(vector<int> &A) {
     TreeNode* res = createTree(res,A,0,A.size()-1);
     return res;
}
