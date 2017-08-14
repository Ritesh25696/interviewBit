Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Note:
You may only use constant extra space.
Example :

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 Note 1: that using recursion has memory overhead
******************************************************************************************************************* 
 
void Solution::connect(TreeLinkNode* A) {
  if(A==NULL)
        return;
    
    TreeLinkNode *cur =A, *leftWall =NULL, *prev =NULL;
    
    while(cur){
        
        while(cur){
            if(cur->left){
                if(prev!=NULL){
                    prev->next = cur->left;
                }
                
                else{
                    leftWall = cur->left;
                }
                prev = cur->left;
            }
            
            if(cur->right){
                if(prev!=NULL){
                    prev->next = cur->right;
                }
                else{
                    leftWall = cur->right;
                }
                prev = cur->right;
            }
            cur = cur->next;
        }
        
        cur = leftWall;
        leftWall = NULL;
        prev = NULL;
    }
}
