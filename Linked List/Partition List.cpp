Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->3->4->5.

**************************************************************************************************************

ListNode* Solution::partition(ListNode* A, int B) {
    if(A == NULL || A->next == NULL)return A;
 ListNode *front = NULL, *back = NULL, *C , *start=NULL , *backstart = NULL;
 while(A != NULL){
     if(A->val < B){
         if(front == NULL){
             front = A;
             A = A->next;
             front->next = NULL;
             start = front;
         }
         else{

            front->next = A;
            A = A->next;
            front= front->next;
            front->next = NULL;
         }
     }
     else if(A->val >= B){
         if(back == NULL){
             
             back = A;
             A = A->next;
             back->next = NULL;
             backstart = back;
         }
         else{
             
             back->next = A;
             A = A->next;
             back = back->next;
             back->next = NULL;
         }
     }
    
 }
 if(start == NULL)return backstart;
 front->next = backstart;
 
 return start;
}
