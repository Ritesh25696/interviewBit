Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*******************************************************************************************************************

ListNode* Solution::swapPairs(ListNode* A){
  if(A == NULL || A->next == NULL)return A;
  ListNode *temp1 = A;
  ListNode *temp2 = temp1->next;
  ListNode *temp3 = temp2->next;
  temp2->next = temp1;
  temp1->next = temp3;
  A = temp2;
  ListNode *prev = A->next;
  temp1 = A->next->next;
  while(temp1 != NULL && temp1->next != NULL){
      temp2 = temp1->next;
      temp3 = temp2->next;
      temp2->next = temp1;
      temp1->next = temp3;
      prev->next = temp2;
      prev = temp1;
      temp1 = temp1->next;
  }
  return A;
}
