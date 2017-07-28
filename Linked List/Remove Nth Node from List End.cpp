Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
* If n is greater than the size of the list, remove the first node of the list. 
Try doing it using constant additional space.

*********************************************************************************************************************************

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
   ListNode* temp = A;
   int count =0;
   while(temp != NULL){
       temp = temp->next;
       count++;
   }
   if(B >= count ){
    A = A->next;
    return A;
   }
   int toRemove = count-B+1;
   temp = A;
   for(int i=0 ; i<toRemove-2 ; i++){
       temp = temp->next;
   }
   ListNode *temp2 = temp->next;
   temp->next  = temp2->next;
   delete(temp2);
   return A;
   
}
