Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

******************************************************************************************************************

ListNode* Solution::rotateRight(ListNode* A, int B) {
    
  ListNode* temp = A;
   int count =0;
   while(temp != NULL){
       temp = temp->next;
       count++;
   }
   B = B%count;
   if(B == 0) return A;
   int toRemove = count-B+1;
   temp = A;
   for(int i=0 ; i<toRemove-2 ; i++){
       temp = temp->next;
   }

   ListNode *temp2 = temp->next;
   temp->next = NULL;
   ListNode *temp3 = temp2;
   while(temp3->next != NULL)temp3 = temp3->next;
   temp3->next = A;
   A = temp2;
   return A;
    
}
