Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

****************************************************************************************************************************************

ListNode * reverse(ListNode * A){
     ListNode *current =A , *prev = NULL , *next;
     while(current != NULL){
         next = current->next;
         current->next = prev;
         prev = current;
         current = next;
     }
     A = prev;
     return A;
 }
 
ListNode* Solution::reorderList(ListNode* A) {
   ListNode *temp = A;
   int count = 0;
   while(temp != NULL){
       temp = temp->next;
       count++;
   }
   if(count< 3)return A;
   int mid = count/2;
   ListNode *temp1 = A;
   for(int i=0 ; i<=mid-2 ; i++){
   temp1 = temp1->next;    
   }
   ListNode *temp2 = temp1->next;
   temp1->next = reverse(temp2);
   if(count  == 3)return A;
   temp2 = temp1->next;
   temp1->next = NULL;
   temp1 = A;
   ListNode*temp3 , *temp4;
   while(temp1 != NULL && temp2 != NULL){
       temp3 = temp1->next;
       temp1->next = temp2;
       temp1 = temp3;
       temp4 = temp2->next;
       temp2->next = temp1;
       temp2 = temp4;
   }
   if(temp4 != NULL){
   temp1 = A;
   while(temp1->next != NULL)temp1 = temp1->next;
   temp1->next = temp4;}

   return A;
}
