Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3

************************************************************************************************************************************
TreeNode* makeTree(ListNode *&head, int n){
    if(n<=0){
        return NULL;
    }
    TreeNode *lft = makeTree(head, n/2);
    TreeNode *root = new TreeNode(head->val);
    root->left = lft;
    head = head->next;
    root->right = makeTree(head, n-n/2-1);
    return root;
} 
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
   
    if(A == NULL){
        return NULL;
    }
    
    int len = 0;
    ListNode* curr = A;
    
    while(curr != NULL){
        len++;
        curr = curr->next;
    }
    
    return makeTree(A,len);
}
